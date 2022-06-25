
// https://leetcode.com/problems/remove-invalid-parentheses/

class Solution
{
public:
    vector<string> res;
    unordered_map<string, int> m;
    int invalid_count(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (st.empty())
                    st.push(s[i]);
                else if (st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
        }

        return st.size();
    }

    void solve(string s, int x)
    {
        if (x < 0)
        {
            return;
        }

        if (m[s] != 0)
            return;

        m[s]++;

        if (x == 0)
        {
            if (!invalid_count(s))
                res.push_back(s);

            return;
        }

        for (int i = 0; i < s.size(); i++)
        {
            string l = s.substr(0, i);
            string r = s.substr(i + 1, s.size());

            solve(l + r, x - 1);
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        int x = invalid_count(s);
        solve(s, x);
        return res;
    }
};