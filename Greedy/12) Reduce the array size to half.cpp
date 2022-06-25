// https://leetcode.com/problems/reduce-array-size-to-the-half/

// Time Complexity : O(nlogn) (map+sorting)
// Space Complexity : O(n)

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        map<int, int> mp;
        vector<pair<int, int>> vp;
        for (auto x : arr)
        {
            mp[x]++;
        }

        for (auto x : mp)
        {
            vp.push_back({x.second, x.first});
        }

        sort(vp.rbegin(), vp.rend());
        int cnt = 0;
        int total = arr.size();
        for (auto x : vp)
        {
            total -= x.first;
            cnt++;
            if (total <= arr.size() / 2)
                break;
        }
        return cnt;
    }
};

// Time Complexity : O(n) (map+counting sort)
// Space Complexity : O(n)

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> cnt;
        for (int x : arr)
            ++cnt[x];

        vector<int> counting(n + 1);
        for (auto [_, freq] : cnt)
            ++counting[freq];

        int ans = 0, removed = 0, half = n / 2, freq = n;
        while (removed < half)
        {
            ans += 1;
            while (counting[freq] == 0)
                --freq;
            removed += freq;
            --counting[freq];
        }
        return ans;
    }
};