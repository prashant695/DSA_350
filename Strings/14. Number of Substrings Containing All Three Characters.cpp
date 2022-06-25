// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

// Problem is a minor version of
// https://leetcode.com/problems/subarrays-with-k-different-integers/

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int m[3] = {0};
        int l = 0, r = 0, cnt = 0, n = s.size();

        while (r < n)
        {
            m[s[r] - 'a']++;
            while (m[0] && m[1] && m[2])
            {
                cnt += n - r;
                m[s[l++] - 'a']--;
            }
            r++;
        }
        return cnt;
    }
};