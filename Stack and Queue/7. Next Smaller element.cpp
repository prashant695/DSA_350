
// Method - 1 (BruteForce)
// Time - O(n2)

// Method - 2 (Using stack)
class solution
{
public:
    vector<long long> nextsmallerElement(vector<long long> arr, int n)
    {
        stack<long long> st;
        vector<long long> res(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.empty() == false and st.top() >= arr[i])
                st.pop();

            if (st.empty())
                res[i] = -1;
            else
                res[i] = st.top();

            st.push(arr[i]);
        }
        return res;
    }
};