// https://leetcode.com/problems/counting-bits/

// Method-1
// Bruteforce

// Method-2
// Recursion + Memoisation
class Solution
{
public:
    int dp[100002];
    int fun(int n)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        if (n % 2)
            return dp[n] = 1 + fun(n / 2);
        else
            return dp[n] = fun(n / 2);
    }
    vector<int> countBits(int n)
    {
        memset(dp, -1, sizeof(dp));
        vector<int> res(n + 1);
        for (int i = 0; i <= n; i++)
        {
            res[i] = fun(i);
        }
        return res;
    }
};

// DP Solution
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> v(num + 1, 0);
        for (int i = 0; i <= num; i++)
        {
            v[i] = v[i / 2];
            if (i & 1)
                v[i] += 1;
        }
        return v;
    }
};