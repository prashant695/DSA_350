// https://practice.geeksforgeeks.org/problems/number-of-provinces/1/

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1;

        for (int j = 0; j < adj[node].size(); j++)
        {
            int nbr = adj[node][j];
            if (nbr == 1 & vis[j] == 0)
                dfs(j, adj, vis);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<int> vis(V + 1, 0);
        int cnt = 0;

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                cnt++;
                dfs(i, adj, vis);
            }
        }

        return cnt;
    }
};

// Kosaraju’s algorithm for strongly connected components.
// Tarjan’s Algorithm to find Strongly Connected Components