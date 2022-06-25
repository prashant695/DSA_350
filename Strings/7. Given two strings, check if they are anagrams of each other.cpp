// https://leetcode.com/problems/valid-anagram/

// Method - 1
// Checking the frequency of characters

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int a[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            a[s[i] - 'a']++;
            a[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (a[i] < 0)
                return false;
        }
        return true;
    }
};

// Method - 2
// Sorting

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};