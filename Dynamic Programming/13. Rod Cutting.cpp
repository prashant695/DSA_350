// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/#

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
  int dp[1001];
  int fun(vector<int> &v, int n, int i)
  {
    if (n == 0)
    {
      return 0;
    }

    if (dp[n] != -1)
      return dp[n];

    int cnt = 0;

    for (int j = 0; j < n; j++)
      cnt = max(cnt, v[j] + fun(v, n - j - 1, j));

    return dp[n] = cnt;
  }
  int cutRod(int price[], int n)
  {
    memset(dp, -1, sizeof dp);
    vector<int> v;
    for (int i = 0; i < n; i++)
      v.push_back(price[i]);

    return fun(v, n, 0);
  }
};
