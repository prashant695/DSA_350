// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1/

// Method - 1
// Sorting
// Time complexity -> O(n logn)

// Method - 3
// Min heap
// Time complexity -> O(n logk)
// Space complexity -> O(k)

class Solution
{
public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> pq;

        for (int i = l; i < r + 1; i++)
        {
            pq.push(arr[i]);

            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};