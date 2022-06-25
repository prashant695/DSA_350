// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/#

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        if (s.size() == 0 or k == 0 or k > s.size())
            return -1;
            
        map<int, int> m;
        int l = 0, r = 0;
        int len = -1, n = s.size(), cnt = 0;

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
            if (cnt == k)
                len = max(len, r - l);
        }

        return len;
    }
}: