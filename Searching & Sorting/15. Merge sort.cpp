// https://leetcode.com/problems/sort-an-array

// Time Complexity
// Best Case: O(nlogn)
// Average Case: O(nlogn)
// Worst Case: O(nlogn)

// Space Complexity: O(n)

// Stable: YES

// Recurrence Relation: T(n) = 2T(n / 2) + O(n)

void merge(vector<int> &nums, int l, int m, int h)
{
    int n1 = m - l + 1, n2 = h - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = nums[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = nums[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 and j < n2)
    {
        if (left[i] <= right[j])
            nums[k++] = left[i++];
        else
            nums[k++] = right[j++];
    }
    while (i < n1)
        nums[k++] = left[i++];
    while (j < n2)
        nums[k++] = right[j++];
}

void mergeSort(vector<int> &nums, int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }
}
vector<int> sortArray(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}