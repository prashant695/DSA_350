// https://leetcode.com/problems/defanging-an-ip-address/

// Method - 1
class Solution
{
public:
    string defangIPaddr(string address)
    {
        string res = "";
        for (int i = 0; i < address.size(); i++)
        {
            if (address[i] == '.')
                res += "[.]";
            else
                res += address[i];
        }
        return res;
    }
};

// Method - 2
class Solution
{
public:
    string defangIPaddr(string address)
    {
        for (int i = 0; i < address.size(); i++)
            if (address[i] == '.')
                address.insert(i, "["), address.insert(i + 2, "]"), i += 2;

        return address;
    }
};

// Method - 3
class Solution
{
public:
    string defangIPaddr(string address)
    {
        string s = "[.]";
        for (int i = 0; i < address.size(); i++)
            if (address[i] == '.')
                address.replace(i, 1, s), i += 2;

        return address;
    }
};

// Method - 4
class Solution
{
public:
    string defangIPaddr(string address)
    {
        return regex_replace(address, regex("[.]"), "[.]");
    }
};