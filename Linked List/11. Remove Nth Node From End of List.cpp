// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Method - 1
// Count the number of nodes
// Delete the nth node

// Method - 2

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *p1 = start, *p2 = start;
        for (int i = 0; i <= n; i++)
            p1 = p1->next;
        while (p1)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *tmp = p2->next;
        p2->next = p2->next->next;
        delete tmp;
        return start->next;
    }
};