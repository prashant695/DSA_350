/// https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1/

// Treat every 0 in the array as -1
// Now the question becomes count of 0 sum subarrays

class Solution
{
public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        int len = 0, sum = 0;
        unordered_map<int, int> m;

        m[0] = 1;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i] == 0 ? -1 : 1;
            m[sum]++;
        }

        for (auto it : m)
            len += (it.second * (it.second - 1)) / 2;

        return len;
    }
};

