// https://leetcode.com/problems/reorganize-string/

// Method - 1
// Max Heap
// TC: O(n logn)
// SC: O(n)

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
// TC: O(n)
// SC: O(n + 26)
// Another approach is to fill all the even positions of the result string first,
// with the highest frequency character.
// If there are still some even positions remaining, fill them first.
// Once even positions are done, then fill the odd positions.
// This way, we can ensure that no two adjacent characters are the same.
class Solution
{
public:
    string reorganizeString(string s)
    {
        map<char, int> m;
        int max_freq = 0, max_char;
        int n = s.size();

        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
            if (m[s[i]] > max_freq)
            {
                max_freq = m[s[i]];
                max_char = s[i];
            }
        }

        string res(s.size(), 0);

        if (2 * max_freq > (n + 1))
            return "";

        int idx;

        for (idx = 0; idx < s.size() and max_freq >= 1; idx += 2)
            res[idx] = max_char, max_freq--;

        m[max_char] = 0;

        for (int i = 'a'; i <= 'z'; i++)
        {
            while (m[i] > 0)
            {
                idx = (idx >= n) ? 1 : idx;
                res[idx] = i;
                idx += 2;
                m[i]--;
            }
        }

        return res;
    }
};