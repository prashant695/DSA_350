// https://leetcode.com/problems/merge-k-sorted-lists/

// Method - 1
// Min heap
// TC: O(n * k * log(k))
// SC: O(k)

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;

        ListNode *dummy = new ListNode(0);
        ListNode *h = dummy;
        priority_queue<pair<int, ListNode *>> q;

        for (int i = 0; i < lists.size(); i++)
            if (lists[i])
                q.push({lists[i]->val * -1, lists[i]});

        while (q.empty() == false)
        {
            ListNode *temp = q.top().second;

            q.pop();
            dummy->next = temp;
            dummy = temp;
            if (temp->next)
                q.push({temp->next->val * -1, temp->next});
        }
        return h->next;
    }
};