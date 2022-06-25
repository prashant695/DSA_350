/// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1#

// Time Complexity : O(n*26)
// Space Complexity : O(26)
class Solution
{
public:
    bool IsEqual(unordered_map<char, int> &p, unordered_map<char, int> &t)
    {
        if (p.size() > t.size())
        {
            for (auto it : p)
                if (it.second != t[it.first])
                    return 0;
        }
        else
        {
            for (auto it : t)
                if (it.second != p[it.first])
                    return 0;
        }
        return 1;
    }
    int search(string pat, string txt)
    {
        unordered_map<char, int> t, p;
        int cnt = 0;
        for (int i = 0; i < pat.size(); i++)
        {
            p[pat[i]]++;
            t[txt[i]]++;
        }

        for (int i = pat.size(); i < txt.size(); i++)
        {
            if (IsEqual(p, t))
                cnt++;

            t[txt[i]]++;
            t[txt[i - pat.size()]]--;
        }
        if (IsEqual(p, t))
            cnt++;

        return cnt;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(26)

class Solution
{
public:
    int search(string pat, string txt)
    {
        map<int, int> mp;

        for (auto x : pat)
        {
            mp[x]++;
        }

        int i = 0, j = 0, cnt = 0;

        while (j < txt.size())
        {
            if (!mp.size())
            {
                cnt++;
                i++;
                mp[txt[i]]++;
                if (mp[txt[i]] == 0)
                    mp.erase(txt[i]);
            }
            else
            {
                mp[txt[j]]--;
                j++;
            }
        }

        return cnt;
    }
};