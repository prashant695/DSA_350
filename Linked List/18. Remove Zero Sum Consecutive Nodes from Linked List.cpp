// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

// Method - 1

// Convert the linked list into an array.
// While you can find a non-empty subarray with sum = 0, erase it.
// Convert the array into a linked list.

// Method - 2
// BruteForce
ListNode *removeZeroSumSublists(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    for (ListNode *i = dummy; i; i = i->next)
    {
        int sum = 0;
        for (ListNode *j = i->next; j; j = j->next)
        {
            sum += j->val;
            if (sum == 0)
            {
                i->next = j->next;
            }
        }
    }
    return dummy->next;
}

// Method - 3
ListNode *removeZeroSumSublists(ListNode *head)
{
    ListNode *dummy = new ListNode();
    dummy->next = head;
    unordered_map<int, ListNode *> ump;
    int sum = 0;

    for (ListNode *i = dummy; i; i = i->next)
    {
        sum += i->val;
        ump[sum] = i;
    }
    sum = 0;
    for (ListNode *i = dummy; i; i = i->next)
    {
        sum += i->val;
        i->next = ump[sum]->next;
    }
    return dummy->next;
}