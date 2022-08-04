class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> m1, m2;

        int res = INT_MAX;
        string result;

        for (char x : t)
            m1[x]++;

        int i = 0, j = 0;
        int lettercount = 0;

        while (i < s.size())
        {
            if (m1.find(s[i]) != m1.end())
            {
                m2[s[i]]++;
                if (m2[s[i]] <= m1[s[i]])
                    lettercount++;
            }

            if (lettercount >= t.size())
            {
                while (m1.find(s[j]) == m1.end() || m2[s[j]] > m1[s[j]])
                {
                    m2[s[j]]--;
                    j++;
                }
                if (i - j + 1 < res)
                {
                    res = i - j + 1;
                    result = s.substr(j, res);
                }
            }
            i++;
        }
        return result;
    }
};