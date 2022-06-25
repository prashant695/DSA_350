// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution
{
public:
    int isvowel(char c)
    {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
    int maxVowels(string s, int k)
    {
        int cnt = 0;
        for (int i = 0; i < k; i++)
            if (isvowel(s[i]))
                cnt++;

        int res = cnt;

        for (int i = k; i < s.size(); i++)
        {
            if (isvowel(s[i - k]))
                cnt--;
            if (isvowel(s[i]))
                cnt++;

            res = max(res, cnt);
        }
        return res;
    }
};