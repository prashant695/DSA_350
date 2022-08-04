// Time Complexity -> O(V+E)
// Space Complexity -> O(V)

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[v];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }
    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "--->";
            for (auto node : l[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }
    bool dfsHelper(int node, vector<bool> &vis, vector<bool> &dfsVis)
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        for (auto it : l[node])
        {
            if (!vis[it])
            {
                if (dfsHelper(it, vis, dfsVis))
                    return true;
            }
            else if (dfsVis[it])
            {
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }
    bool contains_cycle()
    {
        vector<bool> vis(V, 0);
        vector<bool> dfsVis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                if (dfsHelper(i, vis, dfsVis))
                    return 1;
        }
        return 0;
    }
};
int main()
{
    Graph g(3);
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 1, 0);
    if (g.contains_cycle())
        cout << "Cycle Detected!!\n";
    else
        cout << "Cycle Not Detected!!\n";
    return 0;
}
