//https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Method - 1
// Bruteforce
// Time -> O(n3)

// Method - 2
// set + sliding window
// Time -> O(2n)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int l = 0, r = 0;
        int len = 0, n = s.size();

        while (r < n)
        {
            while (st.find(s[r]) != st.end())
            {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};

// Method - 3 (Optimised method - 2)
// HashMap + sliding window
// Time -> O(n)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> m(256, -1);
        int l = 0, r = 0;
        int len = 0, n = s.size();

        while (r < n)
        {
            if (m[s[r]] != -1)
                l = max(m[s[r]] + 1, l);

            m[s[r]] = r;
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};
