// BFS
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
    void bfs(int source, int dest = -1)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *parent = new int[V];
        int *dist = new int[V]{0};

        for (int i = 0; i < V; i++)
            parent[i] = -1;

        q.push(source);
        visited[source] = 1;
        parent[source] = source;
        dist[source] = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto nbr : l[curr])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    parent[nbr] = curr;
                    dist[nbr] = dist[curr] + 1;
                    visited[nbr] = 1;
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            cout << "Shortes dist to " << i << " is " << dist[i] << endl;
        }
        if (dest != -1)
        {
            int temp = dest;
            while (temp != source)
            {
                cout << temp << " -- ";
                temp = parent[temp];
            }
            cout << source << endl;
        }
    }
};
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.bfs(1, 6);
    return 0;
}

// DFS
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
    void dfsHelper(int node, bool *visited)
    {
        visited[node] = true;
        cout << node << ",";
        for (int nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }
    }
    void dfs(int source)
    {
        bool *visited = new bool[V]{0};
        dfsHelper(source, visited);
    }
};
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.dfs(1);
    return 0;
}