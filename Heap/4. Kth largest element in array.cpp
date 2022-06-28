// https://leetcode.com/problems/kth-largest-element-in-an-array/

// Method - 1
// Bubble Sort for k passes
// After 1st pass, we have with ourself the largest element
// After 2nd, we have second largest element too
// After kth pass, we would have kth largest element

// Time complexity -> O(n * k)

// Method - 2
// Sorting
// Time complexity -> O(n logn)

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// Method - 3
// Min heap
// Time complexity -> O(n logk)
// Space complexity -> O(k)

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);

            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};