// https : //leetcode.com/problems/search-a-2d-matrix/

// Method - 1
// BruteForce (Linear search)
// Time -> O(n2)

// Method - 2
// (Binary search for every row)
// Time -> O(nlogn)

class Solution
{
public:
    int binary_search(vector<int> arr, int l, int r, int x)
    {
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (arr[m] == x)
                return 1;

            if (arr[m] < x)
                l = m + 1;

            else
                r = m - 1;
        }

        return 0;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            int sz = matrix[i].size();
            if (matrix[i][0] <= target && matrix[i][sz - 1] >= target)
                if (binary_search(matrix[i], 0, matrix[i].size() - 1, target))
                    return true;
        }
        return false;
    }
};

// Method - 3
// (Two Pointer)
// Time -> O(n)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();

        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
            {
                j--;
            }
            else
                i++;
        }
        return false;
    }
};

// Method - 4
// Convert the given matrix to 1D array
// Then binary Search
// Time -> O(logn) space -> O(n)

// Method - 5
// Optimisation of Method - 4 (no extra space)
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0, h = (n * m) - 1;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (matrix[mid / m][mid % m] == target)
                return 1;
            else if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return 0;
    }
};