// Method - 1
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        string s = "", s2;
        while (head)
        {
            s += head->val;
            head = head->next;
        }
        s2 = s;
        reverse(s.begin(), s.end());
        return s == s2;
    }
};

// Method - 2

class Solution
{
public:
    ListNode *tmp;
    int flg = 0;
    void isPali(ListNode *root)
    {
        if (!root)
            return;
        isPali(root->next);
        if (root->val != tmp->val)
        {
            flg = 1;
            return;
        }
        tmp = tmp->next;
    }
    bool isPalindrome(ListNode *head)
    {
        tmp = head;
        isPali(head);
        return flg == 0;
    }
};

// Method - 3
class Solution
{
public:
    ListNode *head2;
    ListNode *reverseList(ListNode *p)
    {
        if (!p)
            return NULL;
        if (p->next == NULL)
        {
            head2 = p;
            return head2;
        }
        reverseList(p->next);
        ListNode *q = p->next;
        q->next = p;
        p->next = NULL;
        return head2;
    }
    ListNode *middleNode(ListNode *head)
    {
        ListNode *turtle = head, *hare = head;
        while (hare and hare->next and hare->next->next)
        {
            turtle = turtle->next;
            hare = hare->next->next;
        }
        return turtle;
    }
    bool isPalindrome(ListNode *head)
    {

        ListNode *mid = middleNode(head);
        mid->next = reverseList(mid->next);

        mid = mid->next;
        while (mid)
        {
            if (mid->val != head->val)
                return 0;
            mid = mid->next;
            head = head->next;
        }
        return 1;
    }
};