// https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

class Solution
{
public:
    int dp[1002][1002];
    int fun(vector<vector<int>> &matrix, int i, int j)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        int r = matrix.size();
        int c = matrix[0].size();

        if (i >= r or j >= c)
            return dp[i][j] = 0;

        if (matrix[i][j] == 1)
            return dp[i][j] = 1 + min({fun(matrix, i + 1, j), fun(matrix, i, j + 1), fun(matrix, i + 1, j + 1)});
        else
            return dp[i][j] = 0;
    }
    int maxSquare(int n, int m, vector<vector<int>> matrix)
    {
        memset(dp, -1, sizeof(dp));
        int r = n;
        int c = m;
        int ma = INT_MIN;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int val = fun(matrix, i, j);
                ma = max(ma, val);
            }
        }
        return ma;
    }
};

// R-ALTERNATE VERSION (tabulation form)
class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> matrix)
    {
        int cnt = 0;
        int r = matrix.size();
        int c = matrix[0].size();
        int dp[r][c];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                dp[i][j] = matrix[i][j];
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (dp[i][j] && i && j)
                {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
                cnt = max(cnt, dp[i][j]);
            }
        }
        return cnt;
    }
};
