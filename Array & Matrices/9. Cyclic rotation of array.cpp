//https://leetcode.com/problems/rotate-array/

// Method - 1
// Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
// 1) Store the first d elements in a temp array
//   temp[] = [1, 2]
// 2) Shift rest of the arr[]
//  arr[] = [3, 4, 5, 6, 7, 6, 7]
// 3) Store back the d elements
//   arr[] = [3, 4, 5, 6, 7, 1, 2]

// Method - 2
// Rotate one by one d times

void leftRotatebyOne(int arr[], int n)
{
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];

    arr[n - 1] = temp;
}

void leftRotate(int arr[], int d, int n)
{
    for (int i = 0; i < d; i++)
        leftRotatebyOne(arr, n);
}

// Method - 3
// Reversal Algo

class Solution
{
public:
    void reverse(vector<int> &nums, int l, int h)
    {
        while (l < h)
            swap(nums[l++], nums[h--]);
    }
    void lefttrotate(vector<int> &nums, int d)
    {
        int n = nums.size();
        d = d % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, n - d - 1);
        reverse(nums, n - d, n - 1);
    }
    void rightrotate(vector<int> &nums, int d)
    {
        int n = nums.size();
        d = d % n;
        reverse(nums, 0, n - d - 1);
        reverse(nums, n - d, n - 1);
        reverse(nums, 0, n - 1);
    }
};