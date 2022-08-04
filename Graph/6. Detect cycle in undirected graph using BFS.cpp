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
    bool bfsHelper(int s, vector<int> &visited)
    {
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for (auto it : l[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
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
                if (bfsHelper(i, vis))
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
