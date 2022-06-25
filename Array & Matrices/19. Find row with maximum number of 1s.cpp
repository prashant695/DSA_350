// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

// Method - 1
// BruteForce (Linear search)
// Time -> O(mn)

// Method - 2
// (Binary search for every row)
// Find first occurrence of i in every row, number of ones would be m - i, where m = number of columns
// Time -> O(mlogn)

// Method - 3
// Time -> O(n+m)
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int maxx = -1;
        int i = 0, j = m - 1;

        while (i < n and j >= 0)
        {
            if (arr[i][j] == 1)
            {
                maxx = i;
                while (j >= 0 and arr[i][j] == 1)
                    j--;
            }
            else
                i++;
        }

        return maxx;
    }
};