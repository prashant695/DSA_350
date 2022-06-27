// https://leetcode.com/problems/sort-an-array

// Time Complexity
// Best Case: O(n^2)
// Average Case: O(n^2)
// Worst Case: O(n^2)

// Space Complexity: O(1)

// Stable: NO

// Recurrence Relation: T(n) = T(n - 1) + O(n)

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int i, j, k;
        int n = nums.size();
        for (i = 0; i < n - 1; i++)
        {
            for (j = k = i; j < n; j++)
            {
                if (nums[j] < nums[k])
                    k = j;
            }
            swap(nums[i], nums[k]);
        }

        return nums;
    }
};