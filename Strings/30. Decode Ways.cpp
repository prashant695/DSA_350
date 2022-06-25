// https://leetcode.com/problems/decode-ways/

class Solution
{
public:
    int dp[101];
    int fun(string s, int i)
    {
        if (i >= s.size())
            return 1;

        if (s[i] == '0')
            return 0;

        if (i == s.size() - 1)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        int way1 = fun(s, i + 1);
        int way2 = 0;

        int val = stoi(s.substr(i, 2));
        if (val <= 26)
            way2 = fun(s, i + 2);

        return dp[i] = way1 + way2;
    }
    int numDecodings(string s)
    {
        memset(dp, -1, sizeof dp);
        return fun(s, 0);
    }
};
