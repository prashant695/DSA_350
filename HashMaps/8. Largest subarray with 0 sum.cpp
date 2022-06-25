/// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#

// Method - 1
// Bruteforce
// Time -> O(n2)

// Method - 2
// Hashmap
// Time -> O(n) Space -> O(n)

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        int len = 0, sum = 0;
        unordered_map<int, int> first_occ;

        first_occ[0] = -1;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (first_occ.count(sum) == 0)
                first_occ[sum] = i;

            len = max(len, i - first_occ[sum]);
        }

        return len;
    }
};


