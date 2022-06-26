// https://leetcode.com/problems/longest-palindromic-substring/

class Solution
{
public:
    int dp[1001][1001];

    string longestPalindrome(string s)
    {
        string res = "", x;
        int n = s.size();
        for (int i = s.size() - 1; i >= 0; i--)
        {
            x = "";
            for (int j = i; j < s.size(); j++)
            {
                x += s[j];
                if (x.size() == 1)
                {
                    dp[i][j] = 1;
                }
                else if (x.size() == 2)
                {
                    dp[i][j] = x[0] == x[1];
                }
                else if (x.size() >= 3)
                {
                    if (x[0] == x[x.size() - 1] && dp[i + 1][j - 1])
                    {
                        dp[i][j] = 1;
                    }
                }
                else
                    dp[i][j] = 0;

                if (dp[i][j] and x.size() >= res.size())
                    res = x;
            }
        }
        return res;
    }
};
