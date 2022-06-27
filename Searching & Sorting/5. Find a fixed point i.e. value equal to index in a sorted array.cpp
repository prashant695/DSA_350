// https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1/

// Fixed Point - value equal to index

class Solution
{
public:
    int FixedPoint(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mid == nums[mid])
                return mid;
            else if (mid > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};
