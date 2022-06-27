// https://leetcode.com/problems/sort-an-array

// Time Complexity
// Best Case: O(nlogn)
// Average Case: O(nlogn)
// Worst Case: O(n^2)

// Space Complexity: O(logn)

// Stable: NO

int partition(vector<int> &nums, int l, int h)
{
    int i = l - 1, j = l;
    int pivot = nums[h];
    while (j < h)
    {
        if (nums[j] <= pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
        j++;
    }
    swap(nums[i + 1], nums[h]);
    return i + 1;
}
void QuickSort(vector<int> &nums, int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(nums, l, h);
        QuickSort(nums, l, j - 1);
        QuickSort(nums, j + 1, h);
    }
}
vector<int> sortArray(vector<int> &nums)
{
    int n = nums.size();
    QuickSort(nums, 0, n - 1);
    return nums;
}