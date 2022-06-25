/// https://leetcode.com/problems/subarray-sums-divisible-by-k/

// Time Complexity : O(n)
// Space Complexity : O(n)

// Testcase:
// 1, 7, 5 k = 4

// 1 % 4 = 1
// 8 % 4 = 0
// 13 % 4 = 1
class Solution
{
public:
    int subarraysDivByK(vector<int> &arr, int k)
    {
        int len = 0, sum = 0, n = arr.size(), curr;
        unordered_map<int, int> m;

        m[0] = 1;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            curr = ((sum % k) + k) % k;
            m[curr]++;
        }

        for (auto it : m)
            len += (it.second * (it.second - 1)) / 2;

        return len;
    }
};