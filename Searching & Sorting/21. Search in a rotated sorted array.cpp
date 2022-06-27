// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution
{
public:
    int find_pivot_index(vector<int> &nums, int l, int h)
    {
        while (l < h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] > nums[h])
                l = mid + 1;
            else
                h = mid;
        }

        return l;
    }

    int binary_search(vector<int> &nums, int target, int l, int h)
    {
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int idx = find_pivot_index(nums, 0, n - 1);
        // Finding the pivot index at which the array is possibly rotated
        // Is equivalent to finding the index of smallest element
        // Testcase nums = [4, 5, 6, 7, 0, 1, 2] and target = 0
        // Value of idx will be 4

        int res1 = binary_search(nums, target, 0, idx);
        int res2 = binary_search(nums, target, idx, n - 1);

        return max(res1, res2);
    }
};