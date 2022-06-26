// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {

        long long res = arr[0];
        long long curr = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (curr + arr[i] > arr[i])
                curr += arr[i];
            else
                curr = arr[i];

            res = max(res, curr);
        }

        return res;
    }
};

// ALTERNATE VERSION
class Solution
{
public:
    int sum = 0, ma = INT_MIN;
    for (auto x : nums)
    {
        sum += x;
        ma = max(ma, sum);
        if (sum < 0)
            sum = 0;
    }
    return ma;
};