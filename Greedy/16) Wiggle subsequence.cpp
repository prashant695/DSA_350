// https://leetcode.com/problems/wiggle-subsequence/

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        int cnt = 1;
        int val = nums[0] - nums[1];
        for (int i = 1; i < nums.size(); i++)
        {
            int tmp = nums[i] - nums[i - 1];
            if (tmp == 0)
                continue;
            if (val == 0)
                cnt++;
            if ((tmp < 0 and val > 0) or (tmp > 0 and val < 0))
                cnt++;

            val = tmp;
        }

        return cnt;
    }
};

// R-ALTERNATE VERSION
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        vector<int> v;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] > 0)
                v.push_back(1);
            else if (nums[i] - nums[i - 1] < 0)
                v.push_back(-1);
        }

        int search = 0, res = 0, res2 = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (search % 2 == 0)
            {
                if (v[i] == 1)
                    res++, search = 1;
            }
            else if (search % 2 == 1)
            {
                if (v[i] == -1)
                    res++, search = 0;
            }
        }

        search = 1;
        for (int i = 0; i < v.size(); i++)
        {
            if (search % 2 == 0)
            {
                if (v[i] == 1)
                    res2++, search = 1;
            }
            else if (search % 2 == 1)
            {
                if (v[i] == -1)
                    res2++, search = 0;
            }
        }
        return max(res, res2) + 1;
    }
};