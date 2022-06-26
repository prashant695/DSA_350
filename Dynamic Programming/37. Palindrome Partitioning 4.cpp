// https://leetcode.com/problems/palindrome-partitioning-iv/

class Solution
{
public:
    int dp[2001][2001], dp2[2001][2001];
    int ans = 0;

    int palindrome(string &s, int i, int j)
    {
        if (s.size() == 2)
        {
            if (s[0] == s[1])
                dp2[i][j] = 1;
            else
                dp2[i][j] = 0;
        }
        int x = s[0];
        int y = s[s.size() - 1];

        if (x == y && dp2[i + 1][j - 1])
            dp2[i][j] = 1;
        else
            dp2[i][j] = 0;

        return dp2[i][j];
    }

    void countSubstrings(string &s)
    {
        memset(dp2, -1, sizeof(dp2));
        string temp;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            temp = s[i];
            dp2[i][i] = 1;
            for (int j = i + 1; j < s.size(); j++)
            {
                temp += s[j];
                palindrome(temp, i, j);
            }
        }
    }
    int part(int idx, string &s, int cnt, int c)
    {
        if (idx == s.size())
        {
            return cnt - 1;
        }

        if (c < 0)
            return INT_MAX;

        if (dp[idx][cnt] != -1)
            return dp[idx][cnt];

        int mi = INT_MAX;

        for (int i = idx; i < s.size(); i++)
        {
            if (dp2[idx][i])
            {
                int x = part(i + 1, s, cnt + 1, c - 1);
                if (x == 2)
                    ans = 1;
                mi = min(mi, x);
            }
        }
        return dp[idx][cnt] = mi;
    }
    bool checkPartitioning(string s)
    {
        countSubstrings(s);
        memset(dp, -1, sizeof(dp));
        part(0, s, 0, 2);
        return ans == 1;
    }
};