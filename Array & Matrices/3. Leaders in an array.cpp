// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

// Method - 1
// BruteForce O(n2)

// Method - 2
// O(n)

class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> v;
        int max = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (max <= a[i])
            {
                max = a[i];
                v.push_back(max);
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};