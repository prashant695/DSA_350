// https://leetcode.com/problems/find-the-town-judge/

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        map<int, int> m;

        for (int i = 0; i < trust.size(); i++)
        {
            m[trust[i][0]]--;
            m[trust[i][1]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (m[i] == n - 1)
                return i;
        }
        return -1;
    }
};