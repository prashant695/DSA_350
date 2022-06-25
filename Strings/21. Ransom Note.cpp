// https://leetcode.com/problems/ransom-note/

class Solution
{
public:
    // Time:O(n)
    // Space:O(1)
    bool canConstruct(string ransomNote, string magazine)
    {
        int m[26] = {0};
        for (int i = 0; i < magazine.size(); i++)
            m[magazine[i] - 'a']++;

        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (m[ransomNote[i] - 'a'] <= 0)
                return false;
            m[ransomNote[i] - 'a']--;
        }
        return true;
    }
};

// ALTERNATE VERSION

// Time:O(nlogn)
// Space:O(1)
bool canConstruct(string r, string m)
{
    int i = 0, j = 0;
    sort(r.begin(), r.end());
    sort(m.begin(), m.end());
    while (i < r.size() and j < m.size())
    {
        if (r[i] == m[j])
            i++, j++;
        else
            j++;
    }
    if (i == r.size())
        return 1;
    return 0;
}
