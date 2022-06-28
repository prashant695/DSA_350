// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// Method - 1
// Min heap
// TC: O(n * logn)
// SC: O(n)

class Solution
{
public:
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> q;

        long long cnt = 0;

        for (int i = 0; i < n; i++)
            q.push(arr[i]);

        while (q.size() > 1)
        {
            long long x = q.top();
            q.pop();

            long long y = q.top();
            q.pop();

            cnt += (x + y);

            q.push(x + y);
        }

        return cnt;
    }
};