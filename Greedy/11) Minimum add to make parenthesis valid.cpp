
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int flg = 0;
        int cnt = 0;

        for (auto x : s)
        {
            if (x == '(')
                flg++;

            else if (x == ')')
            {
                if (flg >= 1)
                    flg--;
                else
                    cnt++;
            }
        }

        return cnt + flg;
    }
};


// ALTERNATE VERSION

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int val = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!val)
            {
                if (s[i] == '(')
                    val++;
                else if (s[i] == ')')
                    cnt++;
            }
            else
            {
                if (s[i] == '(')
                    val++;
                else if (s[i] == ')')
                    val--;
            }
        }

        return cnt + val;
    }
};
