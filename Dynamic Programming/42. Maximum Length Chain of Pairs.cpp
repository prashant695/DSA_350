// https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end());
        vector<int> v(pairs.size(), 1);
        int res = 1;
        for (int i = 0; i < pairs.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[i][0] > pairs[j][1])
                {
                    v[i] = max(v[i], v[j] + 1);
                    res = max(res, v[i]);
                }
            }
        }

        return res;
    }
};