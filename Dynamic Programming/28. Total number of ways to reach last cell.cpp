// https://leetcode.com/problems/unique-paths/

class Solution
{
public:
    int dp[102][102];
    int fun(int x, int y, int m, int n)
    {
        if (x == m - 1 and y == n - 1)
            return 1;
        if (x == m || y == n)
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];
        return dp[x][y] = fun(x + 1, y, m, n) + fun(x, y + 1, m, n);
    }
    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, m, n);
    }
};

// R-ALTERNATE VERSION (tabulation form)
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int dp[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 or j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Recursive + Memoization
class Solution
{
public:
    int dp[100][100];
    int fun(int x, int y)
    {
        if (x == 0 and y == 0)
            return 1;

        if (x < 0 or y < 0)
            return 0;

        if (dp[x][y] != -1)
            return dp[x][y];

        int w1 = fun(x - 1, y);
        int w2 = fun(x, y - 1);

        return dp[x][y] = w1 + w2;
    }
    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof dp);
        return fun(m - 1, n - 1);
    }
};

// Tabulation
class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        int dp[100][100];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 and j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int w1 = 0, w2 = 0;

                    if (i >= 1)
                        w1 = dp[i - 1][j];

                    if (j >= 1)
                        w2 = dp[i][j - 1];
                    dp[i][j] = w1 + w2;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Space Optimisation
class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 and j == 0)
                    cur[j] = 1;

                else
                {
                    int w1 = 0, w2 = 0;
                    w1 = prev[j];

                    if (j >= 1)
                        w2 = cur[j - 1];

                    cur[j] = w1 + w2;
                }
            }

            prev = cur;
        }
        return prev[n - 1];
    }
};
