// https://leetcode.com/problems/roman-to-integer/

// Method - 1
class Solution
{
public:
    int romanToInt(string s)
    {
        int n = s.size() - 1;
        int cnt = 0;
        for (int i = n; i >= 0; i--)
        {
            if (s[i] == 'I')
                cnt++;
            else if (s[i] == 'V')
            {
                if (i - 1 >= 0 && s[i - 1] == 'I')
                    cnt--, i--;
                cnt += 5;
            }
            else if (s[i] == 'X')
            {
                if (i - 1 >= 0 && s[i - 1] == 'I')
                    cnt--, i--;
                cnt += 10;
            }
            else if (s[i] == 'L')
            {
                if (i - 1 >= 0 && s[i - 1] == 'X')
                    cnt -= 10, i--;
                cnt += 50;
            }
            else if (s[i] == 'C')
            {
                if (i - 1 >= 0 && s[i - 1] == 'X')
                    cnt -= 10, i--;
                cnt += 100;
            }
            else if (s[i] == 'D')
            {
                if (i - 1 >= 0 && s[i - 1] == 'C')
                    cnt -= 100, i--;
                cnt += 500;
            }
            else if (s[i] == 'M')
            {
                if (i - 1 >= 0 && s[i - 1] == 'C')
                    cnt -= 100, i--;
                cnt += 1000;
            }
        }
        return cnt;
    }
};

// Method - 2
class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> m;
        m['M'] = 1000;
        m['D'] = 500;
        m['C'] = 100;
        m['L'] = 50;
        m['X'] = 10;
        m['V'] = 5;
        m['I'] = 1;

        int cnt = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (m[s[i]] < m[s[i + 1]])
                cnt -= m[s[i]];
            else
                cnt += m[s[i]];
        }
        cnt += m[s[s.size() - 1]];

        return cnt;
    }
};
