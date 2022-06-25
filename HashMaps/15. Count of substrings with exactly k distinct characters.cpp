/// https://leetcode.com/problems/subarrays-with-k-different-integers/

// count of substrings with exactly k distinct characters =
// number of substrings with less than equal to k distinct characters  -  number of substrings with less than equal to k-1 distinct characters

class Solution
{
public:
    int SubstringWithLessThanEqualK(string s, int k)
    {
        if (s.size() == 0 or k == 0 or k > s.size())
            return -1;

        map<int, int> m;
        int l = 0, r = 0;
        int len = 0, n = s.size(), cnt = 0;

        while (r < n)
        {
            if (m[s[r]] == 0)
                cnt++;
            m[s[r]]++;
            r++;

            while (cnt > k)
            {
                m[s[l]]--;
                if (m[s[l]] == 0)
                    cnt--;
                l++;
            }
            len += r - l;
        }

        return len;
    }
    int SubstringWithEqualK(string s, int k)
    {
        return SubstringWithLessThanEqualK(s, k) - SubstringWithLessThanEqualK(s, k - 1);
    }
};
