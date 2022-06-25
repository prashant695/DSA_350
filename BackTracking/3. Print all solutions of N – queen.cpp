
// https://leetcode.com/problems/n-queens/

class Solution
{
public:
    bool canmove(vector<string> &grid, int r, int c)
    {
        // for column
        for (int i = 0; i < grid[0].size(); i++)
            if (grid[i][c] == 'Q')
                return 0;

        // for other diagonal
        int i = r - 1, j = c + 1;
        while (i >= 0 and j < grid[0].size())
            if (grid[i--][j++] == 'Q')
                return 0;

        i = r + 1, j = c - 1;
        while (j >= 0 and i < grid.size())
            if (grid[i++][j--] == 'Q')
                return 0;

        // for principal diagonal
        i = r + 1, j = c + 1;
        while (i < grid.size() and j < grid[0].size())
            if (grid[i++][j++] == 'Q')
                return 0;

        i = r - 1, j = c - 1;
        while (i >= 0 and j >= 0)
            if (grid[i--][j--] == 'Q')
                return 0;

        return 1;
    }
    void backtrack(vector<string> &grid, vector<vector<string>> &res, int i, int n)
    {
        if (i == n)
        {
            res.push_back(grid);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (canmove(grid, i, j))
                grid[i][j] = 'Q', backtrack(grid, res, i + 1, n), grid[i][j] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> v;
        string s(n, '.');

        for (int i = 0; i < n; i++)
            v.push_back(s);
        vector<vector<string>> res;

        backtrack(v, res, 0, n);

        return res;
    }
};