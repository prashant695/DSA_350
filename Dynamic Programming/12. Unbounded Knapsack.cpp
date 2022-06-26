// https://leetcode.com/problems/coin-change-2/

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n * amt)
// Space Complexity : O(n * amt)

// Given a knapsack weight W and a set of n items with certain value vali and weight wti,
// we need to calculate the maximum amount that could make up this quantity exactly.
// This is different from classical Knapsack problem,
// here we are allowed to use unlimited number of instances of an item.

class Solution
{
public:
    int dp[5002][302];
    int cnt = 1;
    int fun(vector<int> &coins, int amount, int i)
    {

        if (amount == 0)
            return 1;

        if (i >= coins.size())
            return 0;

        if (dp[amount][i] != -1)
            return dp[amount][i];
        int val1 = 0, val2 = 0, val3 = 0;
        if (coins[i] > amount)
            return fun(coins, amount, i + 1);

        val1 = fun(coins, amount, i + 1);

        val3 = fun(coins, amount - coins[i], i);

        return dp[amount][i] = val1 + val3;
    }
    int change(int amount, vector<int> &coins)
    {
        memset(dp, -1, sizeof dp);
        int val = fun(coins, amount, 0);

        return val;
    }
};
