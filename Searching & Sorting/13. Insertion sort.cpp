// https://leetcode.com/problems/sort-an-array

// Time Complexity
// Best Case: O(n)
// Average Case: O(n^2)
// Worst Case: O(n^2)

// Space Complexity: O(1)

// Stable: YES

// Recurrence Relation: T(n) = T(n - 1) + O(n)

vector<int> InsertionSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        int key = nums[i];
        while (j >= 1 and nums[j - 1] > key)
        {
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = key;
    }
    return nums;
}
