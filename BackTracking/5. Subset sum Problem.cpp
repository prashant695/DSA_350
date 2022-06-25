
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/

// Time complexity: O(sum * n)
// For recursion TC-> O(2^n)

// Space Compexity: O(sum * n)
class Solution
{
public:
    bool flg = 0;
    int dp[10001][101];
    int fun(vector<int> v, int sum, int i)
    {
        int n = v.size();
        if (sum == 0)
        {
            return 1;
        }

        if (i >= n or sum < 0)
        {
            return 0;
        }

        if (dp[sum][i] != -1)
            return dp[sum][i];

        return dp[sum][i] = fun(v, sum, i + 1) + fun(v, sum - v[i], i + 1);
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        memset(dp, -1, sizeof dp);
        return fun(arr, sum, 0);
    }
};