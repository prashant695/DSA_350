// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k

// Method
// if the remainder rem and k-rem do not have the same frequency, return false
// Also, when frequency of rem=0 is not even, return false
class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        unordered_map<int, int> m;

        for (int x : arr)
            m[(k + x % k) % k]++;
        // For handling negative numbers

        if (m[0] % 2 == 1)
            return 0;

        for (auto it : m)
        {
            int i = it.first;

            if (i)
                if (m[i] != m[k - i])
                    return 0;
        }
        return 1;
    }
};