// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
public:
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, res;
    void dfs(string digits, char c, string ans, int idx)
    {
        if (c == '\0')
        {
            res.push_back(ans);
            return;
        }

        for (int i = 0; i < v[c - '0'].size(); i++)
        {
            dfs(digits, digits[idx + 1], ans + v[c - '0'][i], idx + 1);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};

        dfs(digits, digits[0], "", 0);
        return res;
    }
};