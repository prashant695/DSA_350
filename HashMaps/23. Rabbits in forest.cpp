/// https://leetcode.com/problems/rabbits-in-forest/

// Two Pass
class Solution
{
public:
    int numRabbits(vector<int> &a)
    {
        map<int, int> m;
        int cnt = 0;
        for (int i = 0; i < a.size(); i++)
        {
            m[a[i]]++;
            if (m[a[i]] == a[i] + 1)
            {
                cnt += m[a[i]];
                m[a[i]] = 0;
            }
        }

        for (auto it : m)
            if (it.second > 0)
                cnt += it.first + 1;

        return cnt;
    }
};

// One Pass
class Solution
{
public:
    int numRabbits(vector<int> &a)
    {
        map<int, int> m;
        int cnt = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (m[a[i]] == 0)
                cnt += a[i] + 1;
            m[a[i]]++;
            if (m[a[i]] == a[i] + 1)
                m[a[i]] = 0;
        }
        return cnt;
    }
};