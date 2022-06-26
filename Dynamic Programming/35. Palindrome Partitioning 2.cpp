// https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution
{
public:
    int dp[2001][2001];
    bool ispali(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return 0;
            i++, j--;
        }
        return 1;
    }
    int part(int idx, string &s, int cnt)
    {
        if (idx == s.size())
        {
            return cnt - 1;
        }

        if (dp[idx][cnt] != -1)
            return dp[idx][cnt];

        int mi = INT_MAX;

        for (int i = idx; i < s.size(); i++)
        {
            if (ispali(idx, i, s))
            {
                mi = min(mi, part(i + 1, s, cnt + 1));
            }
        }
        return dp[idx][cnt] = mi;
    }
    int minCut(string s)
    {
        memset(dp, -1, sizeof(dp));
        return part(0, s, 0);
    }
};

// ALTERNATE VERSION
class Solution
{
public:
    vector<vector<string>> res;
    int dp[2002][2002];
    bool isPalindrome(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
            {
                return false;
            }
        }
        return true;
    }
    int fun(string &s, int i, int j)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        if (i >= j or isPalindrome(s, i, j))
            return 0;

        int mi = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int left = 0, right = 0;

            left = isPalindrome(s, i, k);
            if (!left)
                continue;

            right = fun(s, k + 1, j);
            int count = 1 + right;
            mi = min(mi, count);
        }
        return dp[i][j] = mi;
    }
    int minCut(string s)
    {
        memset(dp, -1, sizeof(dp));
        return fun(s, 0, s.size() - 1);
    }
};