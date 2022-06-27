// https://leetcode.com/problems/3sum-closest/

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int x, y, res = 1001;
        for (int i = 0; i < nums.size(); i++)
        {
            x = i + 1;
            y = nums.size() - 1;
            while (x < y)
            {
                if (abs(target - (nums[i] + nums[x] + nums[y])) < abs(res - target))
                    res = (nums[i] + nums[x] + nums[y]);

                if (nums[i] + nums[x] + nums[y] < target)
                    x++;
                else
                    y--;
            }
        }
        return res;
    }
};

// ALTERNATE VERSION
int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int mi = INT_MAX, res;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int left = i + 1, right = nums.size() - 1;
        while (left < right)
        {
            int tmp = (nums[i] + nums[left] + nums[right]);
            if (tmp > target)
                right--;
            else
                left++;
            if (mi > abs(tmp - target))
            {
                mi = abs(tmp - target);
                res = tmp;
            }
        }
    }
    return res;
}