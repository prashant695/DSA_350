// Topological Sort (Kahn's Algorithm)

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

    bool contains_cycle()
    {
        queue<int> q;
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : l[i])
            {
                indegree[it]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : l[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (cnt == V)
            return false;
        return true;
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
