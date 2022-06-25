// https://practice.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

// Tc -> O(n)
// SC -> O(1) for Iterative version 
//       O(n) for recursive version

bool arraySortedOrNot(int arr[], int n)
{
    if (n == 1)
        return 1;
    return (arr[n - 1] >= arr[n - 2] && arraySortedOrNot(arr, n - 1));
}