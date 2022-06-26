// https://leetcode.com/problems/house-robber/

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    int dp[102][102];
    int fun(vector<int> &nums, int i, bool prev)
    {
        if (i == nums.size())
            return dp[i][prev] = 0;

        if (dp[i][prev] != -1)
            return dp[i][prev];
        int way1 = 0, way2 = 0;
        if (!prev)
            way1 = nums[i] + fun(nums, i + 1, 1);
        way2 = fun(nums, i + 1, 0);
        return dp[i][prev] = max(way1, way2);
    }
    int rob(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return fun(nums, 0, 0);
    }
};

// Method 2 (bottom up)
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int dp[101] = {0};

        dp[0] = nums[0];

        if (nums.size() == 1)
            return dp[0];

        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

        return dp[n - 1];
    }
};

// Method - 3 (Space efficient)
// Time Complexity : O(n)
// Space Complexity : O(1)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int x, y, tmp;
        x = nums[0];
        y = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            tmp = y;
            y = max(x + nums[i], y);
            x = tmp;
        }
        return y;
    }