

#include <bits/stdc++.h>
using namespace std;
bool isChar(char ch)
{

    if (ch >= 'a' and ch <= 'z')
        return 1;
    if (ch >= 'A' and ch <= 'Z')
        return 1;

    return 0;
}

bool isDigit(char ch)
{

    if (ch >= '0' and ch <= '9')
        return 1;

    return 0;
}
// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
string infixToPostfix(string s)
{
    string res;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {

        if (isChar(s[i]) or isDigit(s[i]))
            res += s[i];
        else if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() and prec(st.top()) > prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}
int main()
{
    string exp = "x+y*z/w+u";
    // ++x/*yzwu

    reverse(exp.begin(), exp.end());

    for (auto &x : exp)
    {
        if (x == '(')
            x = ')';
        else if (x == ')')
            x = '(';
    }
    string prefix = infixToPostfix(exp);
    reverse(prefix.begin(), prefix.end());
    cout << prefix;
    return 0;
}