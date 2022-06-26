// https://leetcode.com/problems/n-th-tribonacci-number/

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    int dp[38] = {0};
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        if (dp[n] != 0)
            return dp[n];
        dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return dp[n];
    }
};

// Method 2 (Iterative version) (bottom up)
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n <= 1)
        {
            return n;
        }

        int first = 0, second = 1, third = 1;

        for (int i = 3; i <= n; i++)
        {
            int fourth = first + second + third;
            first = second;
            second = third;
            third = fourth;
        }
        return third;
    }
};
