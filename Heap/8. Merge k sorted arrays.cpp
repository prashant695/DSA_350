// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1/#

// Method - 1
// Bruteforce (Combine all arrays and then sort)
// TC: O(n * k * log(k))
// SC: O(n * k)

// Method - 2
// Min heap
// TC: O(n * k * log(k))
// SC: O(k)
class Solution
{
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<pair<int, pair<int, int>>> q;
        vector<int> ans;
        int i;

        for (i = 0; i < k; i++)
        {
            q.push({arr[i][0] * -1, {i, 1}});
        }

        for (i = 0; i < k * k; i++)
        {
            auto it = q.top();
            int value = it.first;
            int arrayNumber = it.second.first;
            int arrayIndex = it.second.second;
            q.pop();
            ans.push_back(value * -1);
            if (arrayIndex != k)
            {
                q.push({arr[arrayNumber][arrayIndex] * -1, {arrayNumber, arrayIndex + 1}});
            }
        }

        return ans;
    }
};