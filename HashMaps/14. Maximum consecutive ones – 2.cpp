// Problem is similar to
/// https://leetcode.com/problems/max-consecutive-ones-iii/
// Where k = 1

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int cntz = 0, j = 0, res = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                cntz++;
            while (cntz > k)
            {
                if (nums[j] == 0)
                    cntz--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};

