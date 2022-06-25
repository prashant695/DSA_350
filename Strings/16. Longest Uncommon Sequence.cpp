// https://leetcode.com/problems/longest-uncommon-subsequence-i/

// Method - 1
// Generate all possible subsequences and return the length of largest one
// present in one and absent in other
// Time -> O(2^n + 2^m) // n and m are the lengths of 2 strings
// Space -> O(2^n + 2^m)

// Method - 2
class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        return a == b ? -1 : max(a.size(), b.size());
    }
};
