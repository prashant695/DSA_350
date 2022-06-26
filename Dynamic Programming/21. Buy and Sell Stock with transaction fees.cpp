// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution
{
public:
    int dp[50001][2];
    int fun(int idx, vector<int> &prices, int is_empty, int fee)
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
                       max(fun(idx + 1, prices, 0, fee) - prices[idx] - fee, (fun(idx + 1, prices, is_empty, fee)));
        }
        if (is_empty == 0)
        {
            return dp[idx][is_empty] =
                       max(fun(idx + 1, prices, 1, fee) + prices[idx], (fun(idx + 1, prices, is_empty, fee)));
        }
        return 0;
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        memset(dp, -1, sizeof(dp));
        return fun(0, prices, 1, fee);
    }
};