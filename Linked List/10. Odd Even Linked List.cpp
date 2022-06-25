// https://leetcode.com/problems/odd-even-linked-list/

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head or !head->next)
            return head;
        ListNode *odd = head, *even = head->next, *temp = even;

        while (even and even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = temp;
        return head;
    }
};