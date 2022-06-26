// https://leetcode.com/problems/longest-common-subsequence/

class Solution
{
public:
    int dp[1002][1002];
    int LCS(string &text1, string &text2, int i, int j)
    {

        if (i == -1 || j == -1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j])
            return dp[i][j] = 1 + LCS(text1, text2, i - 1, j - 1);

        return dp[i][j] = max(LCS(text1, text2, i - 1, j), LCS(text1, text2, i, j - 1));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        memset(dp, -1, sizeof(dp));
        return LCS(text1, text2, text1.size() - 1, text2.size() - 1);
    }
};

// TABULTAION FORM
class Solution
{
public:
    int longestCommonSubsequence(string nums1, string nums2)
    {
        int dp[1001][1001];
        int res = -1;
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
