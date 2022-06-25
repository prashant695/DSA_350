/// https://leetcode.com/problems/subarray-sum-equals-k/ (Here k=0)

// Method - 1
// Bruteforce
// Time -> O(n2)

// Method - 2
// Hashmap
// Time -> O(n) Space -> O(n)

class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        int len = 0, sum = 0, n = arr.size();
        unordered_map<int, int> m;

        m[0] = 1;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            len += m[sum];
            m[sum]++;
        }

        return len;
    }
};
