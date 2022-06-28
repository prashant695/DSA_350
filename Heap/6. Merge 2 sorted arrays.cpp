// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

//  Input
//  arr1[] = {3}
//  arr2[] = {2, 10}
//  Output
//  arr1[] = {2}
//  arr2[] = {3, 10}

// Method - 1
// Copy the element to another array having size (arr.size() + arr2.size())
// Sort the entire array
// Copy back the array
// TC: O((n + m) log(n + m))
// SC: O(n + m)

// Method - 2
// Copy the element to another array having size (arr.size() + arr2.size())
// Since both the arrays are sorted, copy the elements precisely
// Copy back the array
// TC: O(n + m)
// SC: O(n + m)

// Method - 3
// TC: O(n * m)
// SC: O(1)
class Solution
{
public:
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr1[i] > arr2[0])
            {
                swap(arr1[i], arr2[0]);

                // Insertion sort
                int key = arr2[0];
                int j = 0;
                while (j < m & arr2[j + 1] < key)
                {
                    arr2[j] = arr2[j + 1];
                    j++;
                }
                if (j == m)
                    j--;
                arr2[j] = key;
            }
        }
    }
};

// Method - 4
// Gap Algorithm (Shell sort)
// TC: O((n + m) log(n + m))
// SC: O(1)
class Solution
{
public:
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int gap = ceil((1.0 * n + m) / 2);
        while (gap > 0)
        {

            int i = 0;
            int j = gap;

            while (j < (n + m))
            {

                if (j < n && arr1[i] > arr1[j])
                {
                    swap(arr1[i], arr1[j]);
                }
                else if (j >= n && i < n && arr1[i] > arr2[j - n])
                {
                    swap(arr1[i], arr2[j - n]);
                }
                else if (j >= n && i >= n && arr2[i - n] > arr2[j - n])
                {
                    swap(arr2[i - n], arr2[j - n]);
                }

                j++;
                i++;
            }

            if (gap == 1)
            {
                gap = 0;
            }
            else
            {
                gap = ceil((float)gap / 2);
            }
        }
    }
};

// Method - 5
class Solution
{
public:
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i = n - 1, j = 0;

        while (i >= 0 and j < m)
        {
            if (arr1[i] > arr2[j])
                swap(arr1[i--], arr2[j++]);

            else
                break;
        }

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};