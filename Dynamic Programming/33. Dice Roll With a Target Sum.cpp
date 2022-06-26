// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution
{
public:
    int mod = 1e9 + 7;
    int dp[32][1002];
    int fun(int n, int k, int target)
    {
        if (target == 0 and n == 0)
            return 1;
        if (target <= 0 or n <= 0)
            return 0;

        if (dp[n][target] != -1)
            return dp[n][target];
        int count = 0;
        for (int i = 0; i < k; i++)
        {
            count = count % mod + fun(n - 1, k, target - (i + 1)) % mod;
        }
        return dp[n][target] = count % mod;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        memset(dp, -1, sizeof(dp));
        return fun(n, k, target);
    }
};