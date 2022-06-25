// https://leetcode.com/problems/jump-game/

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int reach = 0;
        for (int i = 0; i <= reach; i++)
        {
            reach = max(reach, i + nums[i]);
            if (reach >= nums.size() - 1)
                return 1;
        }
        return 0;
    }
};

// DP SOLUTION
class Solution
{
public:
    int dp[100005];
    int fun(vector<int> &nums, int i)
    {
        if (i == nums.size() - 1)
            return 1;
        if (nums[i] == 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = 0;
        for (int j = 1; j <= nums[i]; j++)
        {
            if (i + j == nums.size() - 1)
            {
                ans = 1;
                break;
            }
            else
            {
                ans = max(ans, fun(nums, i + j));
                if (ans)
                    break;
            }
        }
        return dp[i] = ans;
    }
    bool canJump(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return fun(nums, 0);
    }
};

// R-ALTERNATE VERSION

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int res = nums[0];
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (res < i)
                return false;
            res = max(res, i + nums[i]);
        }
        return (res >= nums.size() - 1);
    }
};