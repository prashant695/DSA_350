#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    // list<int> *adj, which appears in the declaration of the Graph class, is a pointer to a list<int>.
    // The Graph constructor assigns this pointer to point to the beginning of the array allocated by new.

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[v];
        // new<int>[V] allocates an array of V empty list<int>'s on the heap.
        // This array must be manually freed by calling delete[] on it (probably in the Graph destructor), or the memory will leak.
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
};
int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.printAdjList();
    return 0;
}