// https://leetcode.com/problems/last-stone-weight/

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (int i = stones.size() - 1; i >= 0; i--)
            pq.push(stones[i]);

        while (pq.size() >= 2)
        {
            int val1 = pq.top();
            pq.pop();
            int val2 = pq.top();
            pq.pop();
            pq.push(abs(val1 - val2));
        }
        return pq.top();
    }
};
// 6 6 7 7 9
