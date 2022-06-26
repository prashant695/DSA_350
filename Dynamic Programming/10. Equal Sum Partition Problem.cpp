// https://leetcode.com/problems/partition-equal-subset-sum/

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(sum * n)
// Space Complexity : O(sum * n)
class Solution
{
public:
    int dp[20001][201];
    bool fun(vector<int> &nums, int sum, int i)
    {
        if (i == nums.size())
        {
            if (sum == 0)
                return true;
            return false;
        }

        if (sum < 0)
            return false;

        if (dp[sum][i] != -1)
            return dp[sum][i];

        return dp[sum][i] = fun(nums, sum - nums[i], i + 1) or fun(nums, sum, i + 1);
    }
    bool canPartition(vector<int> &nums)
    {
        memset(dp, -1, sizeof dp);
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2)
            return 0;

        return fun(nums, sum / 2, 0);
    }
};