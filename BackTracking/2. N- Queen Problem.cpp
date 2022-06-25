
// https://leetcode.com/problems/n-queens-ii/

// Time Complexity : O(N!), Since we have N choices in the first row,
// then N-1 choices in the second row and so on so the overall complexity become O(N!)

// Space Complexity: O(N*N), Just the board and recursive stack space

class Solution
{
public:
    int ans = 0;
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
    int backtrack(vector<string> &grid, int i, int n)
    {
        if (i == n)
            ans++;

        for (int j = 0; j < n; j++)
        {
            if (canmove(grid, i, j))
                grid[i][j] = 'Q', backtrack(grid, i + 1, n), grid[i][j] = '.';
        }

        return ans;
    }
    int totalNQueens(int n)
    {
        vector<string> v;
        string s(n, '.');

        for (int i = 0; i < n; i++)
            v.push_back(s);

        backtrack(v, 0, n);

        return ans;
    }
};