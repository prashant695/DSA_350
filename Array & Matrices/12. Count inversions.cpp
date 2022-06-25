// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

// Method - 1
// Merge Sort
class Solution
{
public:
    long long Merge(long long A[], long long l, long long mid, long long h)
    {
        long long i = l, j = mid + 1, k = l, cnt = 0;
        long long B[500001] = {0};
        while (i <= mid && j <= h)
        {
            if (A[i] <= A[j])
                B[k++] = A[i++];
            else
                B[k++] = A[j++], cnt += mid - i + 1;
        }

        for (; i <= mid; i++)
            B[k++] = A[i];
        for (; j <= h; j++)
            B[k++] = A[j];

        for (i = l; i <= h; i++)
            A[i] = B[i];

        return cnt;
    }
    long long MergeSort(long long A[], long long l, long long h)
    {
        long long mid, cnt = 0;
        if (l < h)
        {
            mid = l + (h - l) / 2;
            cnt += MergeSort(A, l, mid);
            cnt += MergeSort(A, mid + 1, h);
            cnt += Merge(A, l, mid, h);
        }
        return cnt;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return MergeSort(arr, 0, N);
    }
};