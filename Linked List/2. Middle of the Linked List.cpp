// https://leetcode.com/problems/middle-of-the-linked-list/

// Method - 1

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *tmp = head;
        int node = 0, cnt = 0;
        while (tmp)
        {
            node++;
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp)
        {
            cnt++;
            if (cnt == ceil((node + 1) / 2.0))
                return tmp;
            tmp = tmp->next;
        }
        return NULL;
    }
};

// Method - 2

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *turtle = head, *hare = head;
        while (hare and hare->next)
        {
            turtle = turtle->next;
            hare = hare->next->next;
        }
        return turtle;
    }
};

// Method - 3

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *mid = head;
        int cnt = 0;
        while (head)
        {
            if (cnt & 1)
                mid = mid->next;
            cnt++;
            head = head->next;
        }
        return mid;
    }
};