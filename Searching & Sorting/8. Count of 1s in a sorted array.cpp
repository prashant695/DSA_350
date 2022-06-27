// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution
{
public:
    int lower_bound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (r - l) / 2 + l;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
    int searchRange(vector<int> &nums)
    {
        int target = 1;
        int idx1 = lower_bound(nums, target);
        int idx2 = lower_bound(nums, target + 1) - 1;
        if (idx1 < nums.size() and nums[idx1] == target)
            return idx2 - idx1 + 1;
        else
            return -1;
    }
};