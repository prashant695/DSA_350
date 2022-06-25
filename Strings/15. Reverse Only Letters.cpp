// https://leetcode.com/problems/reverse-only-letters/

// Method - 1
// Two Pointers
// Time -> O(n)  Space -> O(1)
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {

            if (!isalpha(s[i]))
                ++i;
            else if (!isalpha(s[j]))
                --j;
            else
                swap(s[i++], s[j--]);
        }
        return s;
    }
};

// Method - 2
// Using Stack
// Time -> O(n)  Space -> O(n)
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        stack<char> st;

        for (auto x : s)
            if (isalpha(x))
                st.push(x);

        for (int i = 0; s[i]; i++)
            if (isalpha(s[i]))
                s[i] = st.top(), st.pop();

        return s;
    }
};