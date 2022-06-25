// https://leetcode.com/problems/add-binary/

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        int x = 0, y, z;
        string s = "";
        while (i >= 0 or j >= 0 or x == 1)
        {
            if (i >= 0)
                x += a[i--] - '0';
            if (j >= 0)
                x += b[j--] - '0';
            s += char(x % 2 + '0');
            x = x / 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};


// ALTERNATE VERSION

string addBinary(string num1, string num2)
{
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
    string res;
    int sum = 0;
    while (i >= 0 || j >= 0 || carry)
    {
        sum = carry;
        sum += i >= 0 ? num1[i--] - '0' : 0;
        sum += j >= 0 ? num2[j--] - '0' : 0;
        int ans = sum % 2;
        carry = sum / 2;
        res += ans + '0';
    }
    reverse(res.begin(), res.end());
    return res;
}