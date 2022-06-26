// https://leetcode.com/problems/generate-parentheses/

// Function to generate all combinations of well-formed parentheses.

class Solution
{
public:
    // n-->'('
    //  m--> ')'
    vector<string> res;
    void fun(string str, int n, int m)
    {
        if (n == 0 and m == 0)
            res.push_back(str);
        if (n > 0 and m >= n)
            fun(str + "(", n - 1, m);
        if (m > 0)
            fun(str + ")", n, m - 1);
    }
    vector<string> generateParenthesis(int n)
    {
        string s = "";
        fun(s, n, n);
        return res;
    }
};

// R-ALTERNATE VERSION
class Solution
{
public:
    void fun(int n, int i, string curr, vector<string> &res, int open, int close)
    {
        if (close > open or 2 * open > n)
            return;
        if (i == n)
        {
            if (open == close)
                res.push_back(curr);
            return;
        }

        fun(n, i + 1, curr + '(', res, open + 1, close);
        fun(n, i + 1, curr + ')', res, open, close + 1);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        fun(2 * n, 0, "", res, 0, 0);
        return res;
    }
};