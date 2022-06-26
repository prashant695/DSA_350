// https://leetcode.com/problems/jump-game-ii/

// METHOD-1
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;

        int maxjump = nums[0];
        int currjump = nums[0];
        int cnt = 1;
        // initialising cnt = 1 for the case like [3, 1]
        // currjump

        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxjump = max(maxjump, i + nums[i]);

            if (currjump == i)
            {
                cnt++;
                currjump = maxjump;
            }
        }
        return cnt;
    }
};

// DP Solution
class Solution
{
public:
    int dp[10001];
    int res = INT_MAX;

    int fun(vector<int> &nums, int j)
    {
        if (j >= nums.size() - 1)
        {
            return 0;
        }

        if (nums[j] == 0)
            return 1e6;

        if (dp[j] < 1e6)
            return dp[j];

        for (int i = j + 1; i <= j + nums[j]; i++)
        {
            dp[j] = min(dp[j], 1 + fun(nums, i));
        }

        return dp[j];
    }

    int jump(vector<int> &nums)
    {
        memset(dp, 1e6, sizeof dp);
        return fun(nums, 0);
    }
};