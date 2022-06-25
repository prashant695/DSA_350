// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// Method - 1 (BruteForce)
// Time - O(n2)

// Method - 2 (Using stack)
class solution
{
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> st;
        vector<long long> res(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.empty() == false and st.top() <= arr[i])
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

// ALTERNATE VERSION

class Solution
{
public:
    // Function to find the next greater element for each element of the array.

    // for loop is responsible for.pushing the element to the stack
    // while loop is responsible for popping and each element is pushed
    // and popped only once hence
    // tIME COMPLEXITY -> O(n+n)
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // 5 4 3 6
        // 6 6 6 -1
        stack<int> st;
        st.push(0);
        vector<long long> res(n, -1);
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() and arr[st.top()] < arr[i])
            {
                res[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }

        return res;
    }
};
