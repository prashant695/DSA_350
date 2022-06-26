// https://leetcode.com/problems/fibonacci-number/

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    int dp[31] = {0};
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (dp[n] != 0)
            return dp[n];
        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
};

// Method 2 (Iterative version) (bottom up)
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }

        int first = 0, second = 1;

        for (int i = 2; i <= n; i++)
        {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};

// Method 3 (Iterative version) (bottom up)
// Time Complexity : O(log(n))
// Space Complexity : O(1)

// Formulae used: Fn = {[(√5 + 1)/2] ^ n} / √5
class Solution
{
public:
    int fib(int n)
    {
        double phi = (1 + sqrt(5)) / 2;
        return round(pow(phi, n) / sqrt(5));
    }
};
