// https://leetcode.com/problems/sliding-window-maximum/

// Method - 1
// Bruteforce
// TC: O(nk)
// SC: O(1)

// Method - 2
// Deque
// TC: O(n)
// SC: O(k)
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> q;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            while (q.empty() == false and q.front() <= (i - k))
                q.pop_front();

            while (q.empty() == false and nums[i] > nums[q.back()])
                q.pop_back();

            q.push_back(i);

            if (i >= k - 1)
                res.push_back(nums[q.front()]);
        }

        return res;
    }
};

// Method - 3
// Max heap
// TC: O(n logn)
// SC: O(n)
// For complexity, Consider the testcase -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &a, int k)
    {
        vector<int> ans;
        int n = a.size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
        {
            while (!pq.empty() && pq.top().second <= (i - k))
                pq.pop();

            pq.push({a[i], i});

            if (i >= k - 1)
                ans.push_back(pq.top().first);
        }

        return ans;
    }
};
