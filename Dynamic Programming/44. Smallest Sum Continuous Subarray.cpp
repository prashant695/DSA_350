// https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1/

class Solution
{
public:
  int smallestSumSubarray(vector<int> &arr)
  {
    int res = arr[0];
    int curr = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
      if (curr + arr[i] < arr[i])
        curr += arr[i];
      else
        curr = arr[i];

      res = min(res, curr);
    }

    return res;
  }
};

// ALTERNATE VERSION
class Solution
{
public:
  int smallestSumSubarray(vector<int> &nums)
  {

    int sum = 0, mi = INT_MAX;
    for (auto x : nums)
    {
      sum += x;
      mi = min(mi, sum);
      if (sum > 0)
        sum = 0;
    }
    return mi;
  }
};