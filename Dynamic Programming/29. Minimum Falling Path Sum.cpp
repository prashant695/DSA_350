// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution
{
public:
    int ans = INT_MAX;
    int dp[101][101];
    int fun(vector<vector<int>> &matrix, int i, int j)
    {
        int n = matrix.size();

        if (i == n)
        {
            return 0;
        }

        else if (i < 0 or j < 0 or j >= n or i >= n)
        {
            return INT_MAX;
        }

        else if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = matrix[i][j] + min({fun(matrix, i + 1, j - 1),
                                              fun(matrix, i + 1, j),
                                              fun(matrix, i + 1, j + 1)});
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        memset(dp, -1, sizeof(dp));
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            ans = min(ans, fun(matrix, 0, i));

        return ans;
    }
};
