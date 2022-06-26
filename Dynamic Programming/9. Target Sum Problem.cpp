// https://leetcode.com/problems/target-sum/

// Method 1 (Recursion+Memoisation) (top down)

class Solution
{
public:
    int dp[21][2002];
    int solve(vector<int> &nums, int target, int i, int val)
    {
        if (i == nums.size())
        {
            if (val - 1001 == target)
                return 1;
            return 0;
        }
        if (dp[i][val] != -1)
            return dp[i][val];
        int x = nums[i];
        int a = solve(nums, target, i + 1, val + x);
        int b = solve(nums, target, i + 1, val - x);

        return dp[i][val] = a + b;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        memset(dp, -1, sizeof(dp));
        return solve(nums, target, 0, 1001);
    }
};
