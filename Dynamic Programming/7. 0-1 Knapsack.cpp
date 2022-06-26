// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    int dp[1001][1001];
    int fun(int n, int W, int wt[], int val[], int i)
    {
        if (i == n)
            return 0;

        if (dp[i][W] != -1)
            return dp[i][W];

        if (W >= wt[i])
            return dp[i][W] = max(fun(n, W, wt, val, i + 1), fun(n, W - wt[i], wt, val, i + 1) + val[i]);
        else
            return dp[i][W] = fun(n, W, wt, val, i + 1);
    }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        memset(dp, -1, sizeof dp);
        return fun(n, W, wt, val, 0);
    }
};


// Method 2 (Iterative version) (bottom up)
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        // making and initializing dp array
        int dp[W + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++)
        {
            for (int w = W; w >= 0; w--)
            {

                if (wt[i] <= w)
                    // finding the maximum value
                    dp[w] = max(dp[w],
                                dp[w - wt[i]] + val[i]);
            }
        }
        return dp[W]; // returning the maximum value of knapsack
    }
};