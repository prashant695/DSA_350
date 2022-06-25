// https://leetcode.com/problems/remove-k-digits/

// TC - O(n)
// SC - O(n)

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        int n = num.size();
        string res = "";

        for (int i = 0; i < num.size(); i++)
        {
            if (st.empty() == false and k > 0 and st.top() > num[i])
            {
                st.pop();
                k--;
                i--;
            }
            else
            {
                st.push(num[i]);
            }
        }

        while (st.empty() == false and k >= 1)
        {
            st.pop();
            k--;
        }

        while (st.empty() == false)
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        int i = 0;
        while (res[i] == '0')
            i++;

        res = res.substr(i, res.size());

        return res.size() >= 1 ? res : "0";
    }
};
