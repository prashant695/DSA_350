// https://leetcode.com/problems/valid-parentheses/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; s[i]; i++)
        {
            if (s[i] == '(')
                st.push(s[i]);
            if (s[i] == '{')
                st.push(s[i]);
            if (s[i] == '[')
                st.push(s[i]);

            if (s[i] == ')')
            {
                if (st.empty() == false && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    return 0;
                }
            }
            if (s[i] == '}')
            {
                if (st.empty() == false && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return 0;
                }
            }
            if (s[i] == ']')
            {
                if (st.empty() == false && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return 0;
                }
            }
        }
        if (st.empty() == true)
        {
            return 1;
        }
        return 0;
    }
};

// ALTERNATE VERSION
bool isValid(string s)
{
    stack<char> st;
    for (auto x : s)
    {
        if (x == '(' || x == '{' || x == '[')
            st.push(x);
        else
        {
            if (st.size() == 0)
                return false;
            if (x == ')' and st.top() == '(' || (x == '}' and st.top() == '{') || x == ']' and st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    return st.size() == 0;
}