// https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int a = 0, b = 0;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                a++;
            else
                b++;

            if (a == b)
                cnt++;
        }

        return cnt;
    }
};