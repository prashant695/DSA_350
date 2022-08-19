// https://leetcode.com/problems/intersection-of-two-linked-lists/

// Method - 1
// Bruteforce

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        while (headA)
        {
            ListNode *tmp = headB;
            while (tmp)
            {
                if (headA == tmp)
                    return headA;
                tmp = tmp->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};

// Method - 2
// Using Hashmap

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> m;
        while (headA)
        {
            m[headA]++;
            headA = headA->next;
        }
        while (headB)
        {
            if (m[headB])
                return headB;
            headB = headB->next;
        }

        return nullptr;
    }
};

// Method - 3
// Length Difference

// Count nodes in listA and listB
// If nodes in listA > listB move head in listA by (nodes in A - nodes in B) else vice versa
// Move both the heads parallely and check for the current node value

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *p = headA, *q = headB;
    while (p and q)
    {
        p = p->next;
        q = q->next;
    }
    while (p)
    {
        headA = headA->next;
        p = p->next;
    }

    while (q)
    {
        headB = headB->next;
        q = q->next;
    }
    while (headA and headB and headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}
