// https://leetcode.com/problems/sort-an-array

vector<int> sortArray(vector<int> &nums)
{
    int count[50000] = {0};
    vector<int> output = nums;
    for (auto x : nums)
    {
        count[x]++;
    }

    for (int i = 1; i < 50000; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        count[nums[i]]--;
        output[count[nums[i]]] = nums[i];
    }
    return output;
}