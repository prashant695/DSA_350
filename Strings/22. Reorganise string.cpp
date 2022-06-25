// https://leetcode.com/problems/reorganize-string/

// Method - 1
// Using priority queue
// Time:O(nlogn)
// Space:O(n)

class Solution
{
public:
    string reorganizeString(string s)
    {
        int m[26] = {0};
        for (int i = 0; s[i]; i++)
            m[s[i] - 'a']++;
        priority_queue<pair<int, int>> q;

        s = "";
        for (int i = 0; i < 26; i++)
        {
            if (m[i])
            {
                q.push({m[i], i});
            }
        }
        while (q.size() > 1)
        {
            auto it1 = q.top();
            q.pop();
            auto it2 = q.top();
            q.pop();

            s += it1.second + 'a';
            s += it2.second + 'a';

            it1.first--;
            it2.first--;

            if (it1.first > 0)
                q.push(it1);
            if (it2.first > 0)
                q.push(it2);
        }
        if (q.size() == 1)
        {
            if (q.top().first > 1)
                return "";
            s += q.top().second + 'a';
        }
        return s;
    }
};

// Method - 2
// Place the mostFrequent character at a distance of 2 from other
// Then place the rest of the elements to the vacant place

// S="aaabcde"

// a _ a _ a _  _
// a b a c a d e

// ALTERNATE VERSION

// Time:O(n)
// Space:O(n)
string reorganizeString(string s)
{
    map<int, int> mp;
    for (auto x : s)
    {
        mp[x]++;
    }
    pair<int, int> p = {0, 0};
    for (auto x : mp)
    {
        if (p.second < x.second)
        {
            p.second = x.second;
            p.first = x.first;
        }
    }
    if (p.second > (s.size() + 1) / 2)
        return "";
    string res = s;
    int i = 0;
    for (i = 0; p.second; i += 2)
    {
        p.second--;
        res[i] = p.first;
    }
    mp[p.first] = 0;
    for (auto x : mp)
    {
        while (x.second != 0)
        {
            if (i >= s.size())
            {
                i = 1;
                continue;
            }
            res[i] = x.first;
            x.second--;
            i += 2;
        }
    }
    return res;
}