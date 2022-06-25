// https://leetcode.com/problems/first-unique-character-in-a-string/


class Solution
{
public:
    char firstNonUniqChar(string s)
    {
        int m[26] = {0};
        char ch;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (m[s[i] - 'a'] >= 1)
                ch = s[i];

            m[s[i] - 'a']++;
        }

        return ch;
    }
};