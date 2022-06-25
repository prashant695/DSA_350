// https://leetcode.com/problems/merge-intervals/

// Method - 1
// Using Stack
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        stack<vector<int>> st;
        vector<vector<int>> res;
        for (int i = 0; i < v.size(); i++)
        {
            if (st.empty() == true)
                st.push({v[i][0], v[i][1]});
            else if (v[i][0] <= st.top()[1] && v[i][1] >= st.top()[1])
            {
                int x = st.top()[0];
                st.pop();
                st.push({x, v[i][1]});
            }
            else if (v[i][0] <= st.top()[1] && v[i][1] < st.top()[1])
            {
            }
            else if (v[i][0] > st.top()[1])
                st.push({v[i][0], v[i][1]});
        }
        while (st.empty() == false)
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

// Method - 2
// No auxillary space
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        int n = v.size();
        int mi = v[0][0], ma = v[0][1];
        for (int i = 1; i < n; i++)
        {
            if (v[i][0] <= ma)
            {
                ma = max(ma, v[i][1]);
            }
            else
            {
                res.push_back({mi, ma});
                mi = v[i][0];
                ma = v[i][1];
            }
        }
        res.push_back({mi, ma});
        return res;
    }
};
