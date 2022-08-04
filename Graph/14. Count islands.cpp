// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

class Solution
{
public:
    int dfs(vector<vector<char>> &grid, int i, int j)
    {
        int r = grid.size();
        int c = grid[0].size();

        if (i >= r or i < 0 or j >= c or j < 0 or grid[i][j] == '0')
            return 0;

        grid[i][j] = '0';

        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1) + dfs(grid, i - 1, j - 1) + dfs(grid, i - 1, j + 1) + dfs(grid, i + 1, j - 1) + dfs(grid, i + 1, j + 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                {
                    if (grid[i][j] == '1')
                        cnt++, dfs(grid, i, j);
                }
            }
        }

        return cnt;
    }
};