// https://leetcode.com/problems/add-strings/

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int n1 = num1.size(), n2 = num2.size();
        int i = n1 - 1, j = n2 - 1, carry = 0, x = 0;
        char y;
        string res = "";
        while (i >= 0 || j >= 0)
        {
            x = 0;
            if (i >= 0)
                x += num1[i] - '0', i--;
            if (j >= 0)
                x += num2[j] - '0', j--;
            x += carry;
            if (x >= 10)
                carry = 1;
            else
                carry = 0;
            y = ((x % 10) + '0');
            res += y;
        }
        if (carry)
            res += "1";

        reverse(res.begin(), res.end());
        return res;
    }
};

// ALTERNATE VERSION

string addStrings(string num1, string num2)
{
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
    string res;
    int sum = 0;
    while (i >= 0 || j >= 0 || carry)
    {
        sum = carry;
        sum += i >= 0 ? num1[i--] - '0' : 0;
        sum += j >= 0 ? num2[j--] - '0' : 0;
        int ans = sum % 10;
        carry = sum / 10;
        res += ans + '0';
    }
    reverse(res.begin(), res.end());
    return res;
}