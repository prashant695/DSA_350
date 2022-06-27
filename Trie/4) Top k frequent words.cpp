// https://leetcode.com/problems/top-k-frequent-words/

// Time Complexity : O(n*logn)
// Space Complexity : O(n)

// MAP Solution
class Solution
{
public:
    static bool cmp(pair<int, string> p1, pair<int, string> p2)
    {

        if (p1.first == p2.first)
            return p1.second < p2.second;
        else
            return p1.first > p2.first;
    }
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> mp;
        vector<string> res;

        for (auto x : words)
        {
            mp[x]++;
        }
        vector<pair<int, string>> vp;
        for (auto x : mp)
        {
            vp.push_back({x.second, x.first});
        }

        sort(vp.begin(), vp.end(), cmp);

        for (int i = 0; i < k; i++)
        {
            res.push_back(vp[i].second);
        }

        return res;
    }
};