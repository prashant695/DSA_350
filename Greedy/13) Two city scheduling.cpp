// https://leetcode.com/problems/two-city-scheduling/

// Method 1
// Time Complexity : O(n*logn)
// Space Complexity : O(1)

class Solution
{
    static bool comparator(vector<int> &a, vector<int> &b)
    {
        return a[1] - a[0] > b[1] - b[0];
    }

public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {

        int n = costs.size();
        sort(costs.begin(), costs.end(), comparator);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += i >= n / 2 ? costs[i][1] : costs[i][0];

        return ans;
    }
};

// Method 2

class Solution
{
public:
    // 10 30 400 30
    // 20 200 50 20
    long long dp[102][204];
    long long solve(vector<vector<int>> &costs, int i, int x)
    {

        if (i == costs.size())
        {
            if (x - 100 == 0)
                return 0;
            return INT_MAX;
        }

        if (dp[i][x] != -1)
            return dp[i][x];

        long long a = costs[i][0] + solve(costs, i + 1, x + 1);
        long long b = costs[i][1] + solve(costs, i + 1, x - 1);

        return dp[i][x] = min(a, b);
    }
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        memset(dp, -1, sizeof(dp));
        return solve(costs, 0, 100);
    }
};