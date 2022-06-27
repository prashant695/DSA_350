// https://leetcode.com/problems/4sum/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int x, y;
        vector<vector<int>> v;

        for (int j = 0; j < nums.size(); j++)
        {
            if (j != 0 and nums[j] == nums[j - 1])
                continue;
            for (int i = j + 1; i < nums.size(); i++)
            {
                if (i != j + 1 and nums[i] == nums[i - 1])
                    continue;
                x = i + 1;
                y = nums.size() - 1;
                while (x < y)
                {
                    if ((nums[j] * 1ll + nums[i] + nums[x] + nums[y]) == target)
                    {
                        v.push_back({nums[j], nums[i], nums[x], nums[y]}), x++;

                        while (x < y and nums[x] == nums[x - 1])
                            x++;
                    }

                    if (1ll * nums[j] + nums[i] + nums[x] + nums[y] < target)
                        x++;
                    else
                        y--;
                }
            }
        }
        return v;
    }
};

// ALTERNATE VERSION
map<vector<int>, int> mp;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    if (nums.size() < 4)
        return {};
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; i++)
    {
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                long long tmp = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (tmp == target)
                {
                    if (mp[{nums[i], nums[j], nums[left], nums[right]}] == 0)
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    mp[res[res.size() - 1]]++;
                }
                if (tmp > target)
                    right--;
                else
                    left++;
            }
        }
    }
    return res;
}