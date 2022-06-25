// https://leetcode.com/problems/max-consecutive-ones/

// Method 1
//  Time Complexity : O(n^2)
//  Space Complexity : O(1)

// Method 2
//  Time Complexity : O(n)
//  Space Complexity : O(1)
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int cnt = 0, len = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                len = max(len, cnt);
                cnt = 0;
            }
            else
                cnt++;
        }
        return max(len, cnt);
    }
};