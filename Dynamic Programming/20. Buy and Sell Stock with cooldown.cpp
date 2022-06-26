// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution
{
public:
    int dp[5001][2];
    int fun(int idx, vector<int> &prices, int is_empty)
    {
        if (idx >= prices.size())
        {
            return 0;
        }
        if (dp[idx][is_empty] != -1)
            return dp[idx][is_empty];
        if (is_empty == 1)
        {
            return dp[idx][is_empty] =
                       max(fun(idx + 1, prices, 0) - prices[idx], (fun(idx + 1, prices, is_empty)));
        }
        if (is_empty == 0)
        {
            return dp[idx][is_empty] =
                       max(fun(idx + 2, prices, 1) + prices[idx], (fun(idx + 1, prices, is_empty)));
        }
        return 0;
    }
    int maxProfit(vector<int> &prices)
    {
        memset(dp, -1, sizeof(dp));
        return fun(0, prices, 1);
    }
};