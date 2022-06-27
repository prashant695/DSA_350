// https://leetcode.com/problems/find-peak-element/

// Method - 1
// Bruteforce (O(n))

// Method - 2
// Binary Search
// TC: O(logn(n))
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

// why binary search
// 5  10  20  15
// l mid      r

// SInce 10 is not a peak element
// Now whether to go left or right
// Since the left neighbor(5) is not a peak element and right neighbor(20) is greater than 10
// then it looks like promising one. Hence moving toward right