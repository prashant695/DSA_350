// https://leetcode.com/problems/palindrome-partitioning/

class Solution
{
public:
    bool ispali(int i, int j, string s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return 0;
            i++, j--;
        }
        return 1;
    }
    void part(int idx, string s, vector<vector<string>> &res, vector<string> &v)
    {
        if (idx == s.size())
        {
            res.push_back(v);
            return;
        }

        for (int i = idx; i < s.size(); i++)
        {
            if (ispali(idx, i, s))
            {
                v.push_back(s.substr(idx, i - idx + 1));
                part(i + 1, s, res, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> v;
        part(0, s, res, v);
        return res;
    }
};
