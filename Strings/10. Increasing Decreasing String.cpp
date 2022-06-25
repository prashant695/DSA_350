// https://leetcode.com/problems/increasing-decreasing-string/

class Solution
{
public:
    string sortString(string s)
    {
        map<int, int> m;
        string res = "";
        for (int i = 0; i < s.size(); i++)
            m[s[i] - 'a']++;

        while (res.size() != s.size())
        {
            for (int i = 0; i < 26; i++)
                if (m[i] >= 1)
                {
                    res += i + 'a';
                    m[i]--;
                }

            for (int i = 25; i >= 0; i--)
                if (m[i] >= 1)
                {
                    res += i + 'a';
                    m[i]--;
                }
        }
        return res;
    }
};

// ALTERNATE VERSION

string sortString(string s)
{
    map<char, int> mp;
    for (auto x : s)
    {
        mp[x]++;
    }
    string res;
    while (res.size() != s.size())
    {
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second > 0)
            {
                res += it->first;
                it->second--;
            }
        }

        for (auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            if (it->second > 0)
            {
                res += it->first;
                it->second--;
            }
        }
    }
    return res;
}
