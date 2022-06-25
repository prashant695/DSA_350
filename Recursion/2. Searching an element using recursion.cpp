// https://practice.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1

class solution
{
public:
    int search(int arr[], int N, int X, int i)
    {
        if (i == N)
            return -1;
        if (arr[i] == X)
            return i;
        return search(arr, N, X, i + 1);
    }

    int search(int arr[], int N, int X)
    {
        return search(arr, N, X, 0);
    }
};