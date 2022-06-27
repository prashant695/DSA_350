// https://leetcode.com/problems/sort-an-array

// Time Complexity
// Best Case: O(n)
// Average Case: O(n^2)
// Worst Case: O(n^2)

// Space Complexity: O(1)

// Stable: YES

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int i, j, flag = 0;
        int n = nums.size();
        for (i = 0; i < n - 1; i++)
        {
            flag = 0;
            for (j = 0; j < n - i - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                    flag = 1;
                }
            }
            if (flag == 0)
                break;
        }

        return nums;
    }
};