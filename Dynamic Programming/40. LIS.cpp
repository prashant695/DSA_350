// https://leetcode.com/problems/longest-increasing-subsequence/

// Recursion + Memoisation
class Solution
{
public:
    int dp[2502][2502];
    int fun(vector<int> &nums, int i, int prev)
    {
        if (i < 0)
            return 0;
        if (dp[i][prev] != -1)
            return dp[i][prev];
        int way1 = 0, way2 = 0;

        if (nums[i] < nums[prev])
            way1 = 1 + fun(nums, i - 1, i);

        way2 = fun(nums, i - 1, prev);

        return dp[i][prev] = max(way1, way2);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        nums.push_back(INT_MAX);
        return fun(nums, nums.size() - 2, nums.size() - 1);
    }
};

// DP Solution
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> v(nums.size(), 1);
        int res = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    v[i] = max(v[i], v[j] + 1);
                    res = max(res, v[i]);
                }
            }
        }
        return res;
    }
};

// Using Binary Search
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = lower_bound(v.begin(), v.end(), nums[i]);
            if (it == v.end())
                v.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return v.size();
    }
};