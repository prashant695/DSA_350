//https://leetcode.com/problems/reverse-linked-list/

// Method - 1

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *prev = NULL, *next = NULL;

        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
};

// Method - 2

class Solution
{
public:
    ListNode *head;
    ListNode *reverseList(ListNode *p)
    {
        if (!p)
            return NULL;
        if (p->next == NULL)
        {
            head = p;
            return head;
        }
        reverseList(p->next);
        ListNode *q = p->next;
        q->next = p;
        p->next = NULL;
        return head;
    }
};

// Method - 3

// using stack
// Store the nodes in the stack
// Once all the enteries are done, update head to last location
// Start popping the nodes and store them in the same order untill stack is empty
// Update the next pointer of last node to NULL;

// Method - 4

// using array
// create a linked list
// count the total number of nodes
// initialize an array with the size of count
// store data nodes to the array
// print the array from last to first