// https://leetcode.com/problems/sort-list/

class Solution
{
public:
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *curr = new ListNode(0);
        ListNode *tmp = curr;
        while (head1 and head2)
        {
            if (head1->val < head2->val)
            {
                curr->next = head1;
                head1 = head1->next;
            }
            else
            {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        if (head1)
            curr->next = head1;
        if (head2)
            curr->next = head2;

        return tmp->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL or !head->next)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(fast));
    }
};
