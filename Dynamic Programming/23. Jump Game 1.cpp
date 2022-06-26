// https://leetcode.com/problems/jump-game/

// METHOD-1
class Solution
{
public:
    int dp[10001];

    int fun(vector<int> &nums, int j)
    {
        if (j >= nums.size() - 1)
            return dp[j] = 1;

        if (nums[j] == 0)
            return dp[j] = 0;

        if (dp[j] != -1)
            return dp[j];

        for (int i = j + 1; i <= j + nums[j]; i++)
        {
            if (fun(nums, i))
                return dp[j] = 1;
        }

        return dp[j] = 0;
    }

    bool canJump(vector<int> &nums)
    {
        memset(dp, -1, sizeof dp);
        return fun(nums, 0);
    }
};
