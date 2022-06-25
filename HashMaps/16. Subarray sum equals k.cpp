/// https://leetcode.com/problems/subarray-sum-equals-k/

// Method - 1
// BruteForce
// Time -> O(n3)

// Method - 2
// Optimised BruteForce
// Instead of calculating sum, store the sum in prefix array
// Time -> O(n2) Space -> O(n)

// Method - 3
// Optimised BruteForce
// Instead of calculating sum and storing in prefix array, use sum variable
// Time -> O(n2) Space -> O(1)

// Method - 4
// HashMap
// Time -> O(n) Space -> O(n)

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int s = 0, res = 0;
        unordered_map<int, int> m;
        m[0]++;
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
            if (m.find(s - k) != m.end())
            {
                res += m[s - k];
            }
            m[s]++;
        }
        return res;
    }
};
