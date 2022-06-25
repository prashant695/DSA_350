//https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution
{
public:
    void swap(ListNode *node)
    {
        if (!node)
            return;
        ListNode *first = node->next;
        ListNode *second = NULL;

        if (first)
            second = first->next;
        if (second)
        {
            ListNode *secondNext = second->next;
            second->next = first;
            node->next = second;
            first->next = secondNext;
            swap(first);
        }
    }
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        swap(dummy);
        return dummy->next;
    }
};