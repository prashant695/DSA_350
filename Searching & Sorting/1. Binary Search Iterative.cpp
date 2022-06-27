// https://leetcode.com/problems/binary-search

// TC: O(log(n))
// SC: O(1)

// Recurrence Relation: T(n) = T(n / 2) + O(1)

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1;
    }
};


// why low + (high - low) / 2 and not (low + high) / 2
// Integer overflow when high and low are close to INTEGER.MAX value

// Assume mid is x distance from low
// mid = low + x
// (low + high) / 2 = low + x
// x = (high + low) / 2 - low
// x = (high - low) / 2
// mid = low + (high - low) / 2