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
    bool dfsHelper(int node, int parent, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : l[node])
        {
            if (!vis[it])
            {
                if (dfsHelper(it, node, vis))
                    return true;
            }
            else if (it != parent)
                return true;
        }

        return false;
    }
    bool contains_cycle()
    {
        vector<int> vis(V + 1, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfsHelper(i, -1, vis))
                    return true;
            }
        }

        return false;
    }
};
int main()
{
    Graph g(3);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 1, 1);
    if (g.contains_cycle())
        cout << "Cycle Detected!!\n";
    else
        cout << "Cycle Not Detected!!\n";
    return 0;
}
