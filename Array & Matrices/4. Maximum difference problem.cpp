// find out the maximum difference between any two elements such that larger element appears after the smaller number.

// Similar to     121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Method - 1
// BruteForce

// Method - 2
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        int mi = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            mi = min(mi, prices[i]);
            res = max(res, prices[i] - mi);
        }
        return res;
    }
};

// Method - 3
// First find the difference between the adjacent elements of the array and
// store all differences in an auxiliary array diff[] of size n-1.
// Now this problem turns into finding the maximum sum subarray of this difference array

// Method - 4
// Dynamic Programming

class Solution
{
public:
    int dp[100001][2][1];
    int fun(int idx, vector<int> &prices, int is_empty, int t)
    {
        if (idx >= prices.size() or t == 1)
        {
            return 0;
        }
        if (dp[idx][is_empty][t] != -1)
            return dp[idx][is_empty][t];
            
        if (is_empty == 1)
        {
            return dp[idx][is_empty][t] =
                       max(fun(idx + 1, prices, 0, t) - prices[idx], (fun(idx + 1, prices, is_empty, t)));
        }
        if (is_empty == 0)
        {
            return dp[idx][is_empty][t] =
                       max(fun(idx + 1, prices, 1, t + 1) + prices[idx], (fun(idx + 1, prices, is_empty, t)));
        }
        return 0;
    }
    int maxProfit(vector<int> &prices)
    {
        memset(dp, -1, sizeof(dp));
        int x = fun(0, prices, 1, 0);
        return x;
    }
};

