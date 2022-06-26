// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n * sum)
// Space Complexity : O(n * sum)

// Let sum of subset 1 be s1 and subset 2 with s2
// s1 - s2 = diff (given)
// s1 + s2 = sum of array (logical)
// Therefore adding both eq we get :
// 2s1= diff + sum of array
// s1 = (diff + sum of array)/2;
// Problem reduces to find no of subsets with given sum**

class Solution
{
public:
    int dp[10005][101];
    bool solve(vector<int> &arr, int sum, int i)
    {
        if (sum == 0)
            return 1;

        if (i >= arr.size() or sum < 0)
        {
            return 0;
        }

        if (dp[sum][i] != -1)
            return dp[sum][i];

        return dp[sum][i] = solve(arr, sum - arr[i], i + 1) or solve(arr, sum, i + 1);
    }
    bool isSubsetSum(vector<int> arr, int diff)
    {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
        }
        sum = (sum + diff) / 2;

        return solve(arr, sum, 0);
    }
};