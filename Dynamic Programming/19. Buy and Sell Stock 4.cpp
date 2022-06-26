// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution
{
public:
    int dp[1001][2][102];
    int K;
    int fun(int i, vector<int> &p, int is_empty, int t)
    {
        if (i >= p.size() or t == K)
        {
            return 0;
        }
        if (dp[i][is_empty][t] != -1)
            return dp[i][is_empty][t];

        if (is_empty == 1)
        {
            return dp[i][is_empty][t] =
                       max(fun(i + 1, p, 0, t) - p[i], (fun(i + 1, p, is_empty, t)));
        }
        if (is_empty == 0)
        {
            return dp[i][is_empty][t] =
                       max(fun(i + 1, p, 1, t + 1) + p[i], (fun(i + 1, p, is_empty, t)));
        }
        return 0;
    }
    int maxProfit(int k, vector<int> &p)
    {
        K = k;
        memset(dp, -1, sizeof(dp));
        int x = fun(0, p, 1, 0);
        return x;
    }
};