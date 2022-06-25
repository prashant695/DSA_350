
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1/

// TC: O(4^(n*n))
// SC: O(n*n)

class Solution
{
public:
    vector<string> res;
    void fun(vector<vector<int>> &m, int n, int i, int j, string s)
    {
        if (i < 0 or j < 0 or i >= n or j >= n)
            return;

        if (m[i][j] == 0 or m[i][j] == 2)
            return;

        if (i == n - 1 and j == n - 1)
        {
            res.push_back(s);
            return;
        }

        int temp = m[i][j];

        m[i][j] = 2;

        fun(m, n, i + 1, j, s + "D");
        fun(m, n, i - 1, j, s + "U");
        fun(m, n, i, j + 1, s + "R");
        fun(m, n, i, j - 1, s + "L");

        m[i][j] = temp;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        fun(m, n, 0, 0, "");
        return res;
    }
};