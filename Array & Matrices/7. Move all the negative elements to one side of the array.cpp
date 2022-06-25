// https://practice.geeksforgeeks.org/problems/arranging-the-array1131/1/#

// Method - 0
// Sorting O(n logn) O(1)

// Method - 1
// auxillay array O(n) O(n)

// Method - 2
// Partition process of quicksort O(n) O(1)

void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

// Two Pointer approach
void rearrange(int arr[], int l, int r)
{

    while (l <= r)
    {
        if (arr[l] < 0 && arr[r] < 0)
            l += 1;

        else if (arr[l] > 0 && arr[r] < 0)
        {
            swap(a[l], a[r]);
            l += 1;
            r -= 1;
        }
        else if (arr[l] > 0 && arr[r] > 0)
            r -= 1;
        else
        {
            l += 1;
            r -= 1;
        }
    }
}

// However In all the above mentioned approaches, order is not maintained

// Method - 3
// Modified insertion sort O(n2) O(1)

void rearrange(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];

        if (temp < 0)
        {
            int j = i - 1;
            while (j >= 0 && arr[j] >= 0)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }

            arr[j + 1] = temp;
        }
    }
}

// Method - 4
// Optimised Merge sort O(n logn) O(logn) (for recursive calls)