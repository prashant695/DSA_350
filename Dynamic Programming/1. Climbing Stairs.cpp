// https://leetcode.com/problems/climbing-stairs/

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n)
// Space Complexity : O(n)
class Solution
{
public:
    int res = 0;
    int dp[46];
    int fun(int n)
    {
        if (n == 0)
            return 1;
        else if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];
        return dp[n] = fun(n - 1) + fun(n - 2);
    }
    int climbStairs(int n)
    {
        memset(dp, -1, sizeof(dp));
        return fun(n);
    }
};

// Method 2 (bottom up)
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    int climbStairs(int n)
    {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};