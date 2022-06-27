class Solution
{
public:
    int binary_search(vector<int> &nums, int low, int high, int target)
    {
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

    int find(vector<int> &nums, int target)
    {
        int low = 0, high = 1;
        int val = nums[high];

        while (val < target)
        {
            low = high;
            high = 2 * high;
            val = nums[high];
        }

        return binary_search(nums, low, high, target);
    }
};

// we don't have proper bounds to apply binary search
// To find position of key, we find bounds and then apply binary search

// key = 7
//  0  1  2  3  4  5  6  7  8  9   10 (index)
//  1  2  3  4  5  6  7  8  9  10  11  ... infinte
//  l  h

//  0  1  2  3  4  5  6  7  8  9   10 (index)
//  1  2  3  4  5  6  7  8  9  10  11  ... infinte
//     l  h

//  0  1  2  3  4  5  6  7  8  9   10 (index)
//  1  2  3  4  5  6  7  8  9  10  11  ... infinte
//        l     h

//  0  1  2  3  4  5  6  7  8  9   10 (index)
//  1  2  3  4  5  6  7  8  9  10  11  ... infinte
//              l           h

// Range -> [5, 9] for key = 7