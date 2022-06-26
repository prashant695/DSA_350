// https://leetcode.com/problems/min-cost-climbing-stairs/

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    int dp[1002];

    int fun(vector<int> &cost, int i)
    {
        if (i >= cost.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int x = cost[i] + fun(cost, i + 1);
        int y = cost[i] + fun(cost, i + 2);

        return dp[i] = min(x, y);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        memset(dp, -1, sizeof(dp));
        return min(fun(cost, 0), fun(cost, 1));
    }
};

// Method 2 (bottom up)
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    int helper2(vector<int> &cost, int n)
    {
        if (n == 0 or n == 1)
        {
            return cost[n];
        }
        vector<int> dp(n + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return dp[n];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        return min(helper2(cost, n - 1), helper2(cost, n - 2));
    }
};

// Method 3 (bottom up) (Space optimisation)
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution
{
public:
    int helper3(vector<int> &cost, int n)
    {
        if (n == 0 or n == 1)
        {
            return cost[n];
        }
        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++)
        {
            int temp = cost[i] + min(prev2, prev1);

            prev2 = prev1;
            prev1 = temp;
        }
        return min(prev1, prev2);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        return helper3(cost, n);
    }
};