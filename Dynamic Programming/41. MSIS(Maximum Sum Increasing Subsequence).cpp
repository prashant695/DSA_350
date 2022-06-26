// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1/

class Solution
{

public:
    int maxSumIS(int nums[], int n)
    {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = nums[i];

        int res = nums[0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    v[i] = max(v[i], v[j] + nums[i]);
                    res = max(res, v[i]);
                }
            }
        }
        return res;
    }
};