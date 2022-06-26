// https://leetcode.com/problems/palindrome-partitioning-iii/

class Solution
{
public:
    int dp[101][101];
    int dp2[101][101];
    int change(string s)
    {
        int n = s.length();
        int cc = 0;

        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == s[n - i - 1])
                continue;

            cc += 1;

            if (s[i] < s[n - i - 1])
                s[n - i - 1] = s[i];
            else
                s[i] = s[n - i - 1];
        }

        return cc;
    }

    void all_substrings(string s)
    {
        string tmp;
        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 0;
            tmp = s[i];
            for (int j = i + 1; j < s.size(); j++)
            {
                tmp += s[j];
                dp[i][j] = change(tmp);
            }
        }
    }
    int part(int idx, string s, int k)
    {
        if (k < 0)
            return INT_MAX;

        if (dp2[idx][k] != -1)
            return dp2[idx][k];

        if (k == 0)
            return dp[idx][s.size() - 1];

        int ans = 50001;

        for (int i = idx; i < s.size() - 1; i++)
        {
            {
                ans = min(ans, dp[idx][i] + part(i + 1, s, k - 1));
            }
        }

        return dp2[idx][k] = ans;
    }

    int palindromePartition(string s, int k)
    {
        all_substrings(s);
        if (k == s.size())
            return 0;

        memset(dp2, -1, sizeof dp2);
        return part(0, s, k - 1);
    }
};