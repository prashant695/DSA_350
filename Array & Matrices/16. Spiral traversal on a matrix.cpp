// https://leetcode.com/problems/spiral-matrix/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> v;
        int rl = matrix[0].size(), du = matrix.size() - 1;
        int x = 0, y = -1, cnt2 = rl * (du + 1), cnt = 0;

        while (cnt < cnt2)
        {
            for (int i = 0; i < rl and cnt < cnt2; i++)
            {
                v.push_back(matrix[x][++y]);
                cnt++;
            }
            rl--;

            for (int i = 0; i < du and cnt < cnt2; i++)
            {
                v.push_back(matrix[++x][y]);
                cnt++;
            }
            du--;
            for (int i = 0; i < rl and cnt < cnt2; i++)
            {
                v.push_back(matrix[x][--y]);
                cnt++;
            }
            rl--;
            for (int i = 0; i < du and cnt < cnt2; i++)
            {
                v.push_back(matrix[--x][y]);
                cnt++;
            }
            du--;

            if (rl <= 0 && du <= 0)
            {
                return v;
            }
        }
        return v;
    }
};