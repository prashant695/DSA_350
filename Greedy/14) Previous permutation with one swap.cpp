// https://leetcode.com/problems/previous-permutation-with-one-swap/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    vector<int> prevPermOpt1(vector<int> &arr)
    {

        int idx = arr.size() - 1;
        for (int i = arr.size() - 1; i > 0; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                idx = i;
                for (int j = i; j < arr.size(); j++)
                {
                    if (arr[j] < arr[i - 1])
                    {
                        if (arr[idx] < arr[j])
                        {
                            idx = j;
                        }
                    }
                }
                swap(arr[i - 1], arr[idx]);
                return arr;
            }
        }

        return arr;
    }
};