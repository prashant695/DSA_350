// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1/

// Method - 1
// Counting sort / 2 pass O(2n)

// Two Pass
void sort012(int a[], int n)
{
    int i = 0, tmp;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 0)
        {
            swap(a[j], a[i++]);
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (a[j] == 1)
        {
            swap(a[j], a[i++]);
        }
    }
}

// Method - 2
// Dutch National Flag Algo

void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;

    while (mid <= hi)
    {
        switch (a[mid])
        {
        case 0:
            swap(a[lo++], a[mid++]);
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}