// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#

// Method - 1, 2
// Bruteforce, HashMap

// Method-1
int countKDifference(vector<int> &nums, int k)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (abs(nums[i] - nums[j]) == k)
                cnt++;
        }
    }
    return cnt;
}

// Method-2
int countKDifference(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map[nums[i] + k])
            count += map[nums[i] + k];
        if (map[nums[i] - k])
            count += map[nums[i] - k];
        map[nums[i]]++;
    }
    return count;
}

// Method - 3
// Sorting and Searching

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    int i = 0, j = 1;
    while (i < size and j < size)
    {
        if (i != j and abs(arr[j] - arr[i]) == n)
            return 1;
        else if (arr[j] - arr[i] < n)
            j++;
        else
            i++;
    }
    return 0;
}

// Method-4 (counting sort)
// Drawback -> What if the maximum element in array exceeds INT.MAX value (Memory Wastage :|)
int countKDifference(vector<int> &nums, int k)
{
    int map[101] = {0};
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }
    for (int i = k + 1; i < 101; i++)
    {
        count += map[i] * map[i - k];
    }
    return count;
}
