// https://leetcode.com/problems/reverse-nodes-in-k-group/

// Method - 1(using stack)
// use a stack which will store the nodes of linked list
// firstly, push the k-elements of linked list
// now, pop elements one by one and keep track of previously popped nodes
// point the next pointer of prev node to top element of stack
// repeat untill null is reached
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        stack<ListNode *> s;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *c, *curr = dummy->next, *h = dummy;

        while (curr)
        {
            int cnt = 0;
            while (curr and cnt < k)
            {
                if (cnt == 0)
                    c = curr;
                s.push(curr);
                curr = curr->next;
                cnt++;
            }

            if (cnt == k)
            {
                while (s.empty() == false)
                {
                    ListNode *tmp = s.top();
                    s.pop();
                    dummy->next = tmp;
                    dummy = tmp;
                }
            }
            else
            {
                dummy->next = c;
                return h->next;
            }
        }
        dummy->next = NULL;
        return h->next;
    }
};

// Method - 2 (no extra space)
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head or k == 1)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy, *nex = dummy, *pre = dummy;
        int cnt = 0;
        while (curr->next)
        {
            curr = curr->next;
            cnt++;
        }

        while (cnt >= k)
        {
            curr = pre->next;
            nex = curr->next;

            for (int i = 1; i < k; i++)
            {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }

            pre = curr;
            cnt -= k;
        }
        return dummy->next;
    }
};

