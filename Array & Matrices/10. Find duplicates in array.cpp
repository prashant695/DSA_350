// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            int pos = abs(nums[i]) - 1;
            if (nums[pos] < 0)
            {
                v.push_back(pos + 1);
            }
            else
            {
                nums[pos] *= -1;
            }
        }

        return v;
    }
};
