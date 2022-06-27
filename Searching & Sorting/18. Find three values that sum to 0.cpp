// https://leetcode.com/problems/3sum/

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Method - 1
// Unordered_Map
// TC: O(n^2)
// SC: O(n)

// Method - 2
// Searching And Sorting
// TC: O(n^2)
// SC: O(1)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int low, high, a, target;

        for (int i = 0; i < nums.size();)
        {
            a = nums[i];
            low = i + 1;
            high = nums.size() - 1;
            target = -a;
            while (low < high)
            {
                if (nums[low] + nums[high] < target)
                    low++;
                else if (nums[low] + nums[high] > target)
                    high--;
                else
                {
                    res.push_back({nums[low], nums[high], a});
                    int prev_low = low;
                    int prev_high = high;
                    while (low < nums.size() and nums[low] == nums[prev_low])
                        low++;
                    // Avoid Duplicates
                    while (high > 0 and nums[high] == nums[prev_high])
                        high--;
                }
            }
            int prev_a = a;
            while (i < nums.size() and nums[i] == prev_a)
                i++;
        }
        return res;
    }
};