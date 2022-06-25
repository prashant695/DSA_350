// https://leetcode.com/problems/trapping-rain-water/

// Method - 1
// BruteForce
// Time -> O(n2)

// For every i, look for the maximum height to the left and right of it
// water collected = min(max_ht_left, max_ht_right) - heights[i]

class Solution
{
public:
    int trap(vector<int> &heights)
    {
        int max_ht_left, max_ht_right, cnt = 0, j;
        for (int i = 0; i < heights.size(); i++)
        {
            max_ht_left = 0;
            max_ht_right = 0;

            j = i;
            while (j >= 0)
            {
                max_ht_left = max(max_ht_left, heights[j]);
                j--;
            }

            j = i;
            while (j < heights.size())
            {
                max_ht_right = max(max_ht_right, heights[j]);
                j++;
            }
            cnt += min(max_ht_left, max_ht_right) - heights[i];
        }

        return cnt;
    }
};

// Method - 2
// Optimised Brute Force
// Time -> O(n), space -> O(n)

// Instead of calculating max_ht_left and max_ht_right, store them in prefix array
class Solution
{
public:
    int trap(vector<int> &heights)
    {
        int n = heights.size();
        int pre_left[n], pre_right[n];

        pre_left[0] = heights[0];
        for (int i = 1; i < n; i++)
        {
            pre_left[i] = max(pre_left[i - 1], heights[i]);
        }

        pre_right[n - 1] = heights[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            pre_right[i] = max(pre_right[i + 1], heights[i]);
        }

        int cnt = 0;
        for (int i = 0; i < heights.size(); i++)
        {

            cnt += min(pre_left[i], pre_right[i]) - heights[i];
        }

        return cnt;
    }
};

// Method - 3
// Two Pointer
// Time -> O(n), space -> O(1)
class Solution
{
public:
    int trap(vector<int> &height)
    {

        int n = height.size();
        int left = 0;
        int right = n - 1;
        int res = 0;
        int maxleft = 0, maxright = 0;

        while (left <= right)
        {

            if (height[left] <= height[right])
            {

                if (height[left] >= maxleft)
                    maxleft = height[left];
                else
                    res += maxleft - height[left];

                left++;
            }
            else
            {

                if (height[right] >= maxright)
                    maxright = height[right];
                else
                    res += maxright - height[right];

                right--;
            }
        }
        return res;
    }
};
