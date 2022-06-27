// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

int lower_bound(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (r - l) / 2 + l;
        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int idx1 = lower_bound(nums, target);
    int idx2 = lower_bound(nums, target + 1) - 1;
    if (idx1 < nums.size() and nums[idx1] == target)
        // Testcase -> nums = [2,2] traget = 3
        return {idx1, idx2};
    else
        return {-1, -1};
}

// Upper bound   &   Lower bound

// Lower bound returns an iterator pointing to the first element in the range [first, last) which has a value not less than val
// Upper bound returns an iterator pointing to the first element in the range [first, last) which has a value greater than val

// int v[] = {5,5,5,6,6,6,7,7}

// Lower bound
// lower_bound(v.begin(), v.end(), val)

// 6 -> 3
// 4 -> 0
// 8 -> 8

// Upper bound
// upper_bound(v.begin(), v.end(), val)

// 6 -> 6
// 4 -> 0
// 8 -> 8

// IMPLEMENTATION OF LOWER BOUND
int lower_bound(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (r - l) / 2 + l;
        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

// IMPLEMENTATION OF UPPER BOUND
int upper_bound(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (r - l) / 2 + l;
        if (nums[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}