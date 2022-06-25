// https://leetcode.com/problems/zigzag-conversion/

class Solution
{
public:
    string convert(string s, int n)
    {

        if (n == 1)
            return s;
        vector<string> v(n);

        v[0] += s[0];
        int i = 1, cnt;

        while (i < s.size())
        {
            cnt = 1;
            for (; cnt < n and i < s.size(); i++)
                v[cnt++] += s[i];

            cnt = n - 2;
            for (; cnt >= 0 and i < s.size(); i++)
                v[cnt--] += s[i];
        }

        s = "";
        for (auto x : v)
            s += x;

        return s;
    }
};

// ALTERNATE VERSION
string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    string res;
    vector<string> v(numRows);
    int k = 0;
    int ch = -1;
    numRows--;
    for (int i = 0; i < s.size(); i++)
    {
        v[k] += s[i];
        if (k % numRows == 0)
            ch *= -1;
        if (ch == 1)
            k++;
        else
            k--;
    }
    for (auto x : v)
    {
        res += x;
    }
    return res;
}

// 
string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    string res;
    vector<string> v(numRows);
    int k = 0, ch = -1;
    numRows--;
    for (int i = 0; i < s.size(); i++)
    {
        v[k] += s[i];
        ch = k % numRows == 0 ? ch * -1 : ch;
        k = (ch == 1) ? k + 1 : k - 1;
    }
    for (auto x : v)
        res += x;
    return res;
}