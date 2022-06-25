// https://leetcode.com/problems/gas-station/

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        int sum = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            sum += gas[i] - cost[i];
        }

        if (sum < 0)
            return -1;

        sum = 0;
        int idx = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            sum += gas[i] - cost[i];

            if (sum < 0)
            {
                idx = i + 1;
                sum = 0;
            }
        }

        return idx;
    }
};

// ALTERNATE VERSION

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int cur = 0, tot = 0, ans = 0;
        for (int i = 0; i < cost.size(); i++)
        {
            tot += gas[i] - cost[i];
            cur += gas[i] - cost[i];

            if (cur < 0)
                ans = i + 1, cur = 0;
        }
        if (tot < 0)
            return -1;
        return ans;
    }
};