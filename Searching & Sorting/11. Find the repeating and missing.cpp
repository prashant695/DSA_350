// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

// There are numbers from 1 to n, one numsber is missing, other is repeated
// Testcase -> {2, 1, 2}
// Missing -> 3
// Repeated _> 2

// Method - 1
// Sorting

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *ans = new int[2];
        sort(arr, arr + n);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                ans[0] = arr[i];
            }

            if (arr[i] - arr[i - 1] == 2)
            {
                ans[1] = arr[i - 1] + 1;
            }
        }

        if (arr[0] == 2)
            ans[1] = 1;
        else if (ans[1] == 0)
            ans[1] = n; // {1, 1}

        return ans;
    }
};

// Method - 2
// Storing the frequency

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *ans = new int[2];
        map<int, int> m;

        for (int i = 0; i < n; i++)
            m[arr[i]] = m[arr[i]] + 1;

        for (int i = 1; i <= n; i++)
        {
            if (m[i] == 0)
                ans[1] = i;
            if (m[i] == 2)
                ans[0] = i;
        }

        return ans;
    }
};

// Method - 3
// Use elements as index and mark the visited places

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *ans = new int[2];
        map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            if (arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] *= -1;
            else
                ans[0] = abs(arr[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                ans[1] = i + 1;
        }

        return ans;
    }
};

// Method - 4
// Maths
// x-> Missing element
// y-> Repeated element

// S = (n * (n + 1)) / 2 - x + y
// P = 1 * 2 * 3 * ... * n * y / x (Overflow)

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
//
//
//
//
//
//
// Ques -> Finding two missing element from the array containing 1 to n
// XOR

// Calculate xor of all elements
// xor the result with all numbers from 1 to n
// xor_val would now be the xor of x and y

// Original array = {1, 2, 4, 6}
// Let x = 3, y = 5
// xor_val =   1 1
//           1 0 1
//          -------
//           1 1 0   ->  6

// Find the rightmost set bit
// Divide the entire array into two parts such that one part containing the elements having that bit as set
// Other part containing the elements having that bit as not set

// Array containing set bit
// 2 ^ 6                   ^       2 ^ 3 ^ 6
// From given array                From array 1 to n

// Other array
// 1 ^ 4                   ^       1 ^ 4 ^ 5
// From given array                From array 1 to n
//
//
//
//
//
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// Method - 5
// XOR

int *findTwoElement(int *arr, int n)
{
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 ^= (arr[i] ^ (i + 1));
    }
    int set_bit = (xor1 & (~(xor1 - 1)));
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) & set_bit)
            s1 ^= (i + 1);
        else
            s2 ^= (i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & set_bit)
            s1 ^= (arr[i]);
        else
            s2 ^= (arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == s2)
        {
            swap(s1, s2);
            break;
        }
    }
    int *res = new int(2);
    res[0] = s1;
    res[1] = s2;
    return res;
}
