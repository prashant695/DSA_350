// https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
// Method - 1
// Using auxillary space

// Method - 2
class Solution
{
public:
    int isPalindrome(string s)
    {
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
                return 0;
        }
        return 1;
    }
};