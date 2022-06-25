// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution
{
public:
    int minSteps(string s, string t)
    {
        int cnt = 0;
        int m[26] = {0};

        for (auto x : s)
            m[x - 'a']++;
        for (auto y : t)
            m[y - 'a']--;

        for (int i = 0; i < 26; i++)
            if (m[i] < 0)
                cnt += abs(m[i]);

        return cnt;
    }
};
