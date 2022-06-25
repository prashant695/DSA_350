// https://leetcode.com/problems/reverse-string/

// Method - 1
// Using auxillary space

// Method - 2
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        for (int i = 0; i < s.size() / 2; i++)
        {
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
};