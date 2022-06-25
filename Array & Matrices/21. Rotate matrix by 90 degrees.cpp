// https://leetcode.com/problems/rotate-image/

// Method - 1
// Transpose (Two pass)
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i + 1; j < matrix[i].size(); j++)
            {
                if (j != i)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size() / 2; j++)
            {
                swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]);
            }
        }
    }
};

// Method - 2
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};
