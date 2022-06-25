// https://leetcode.com/problems/merge-k-sorted-lists/

// Method - 1 (using array)
// Traverse all the linked lists and collect the values of the nodes into an array.
// Sort and iterate over this array to get the proper value of nodes.
// Create a new sorted linked list and extend it with the new nodes.

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> v;

        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *tmp = lists[i];
            while (tmp)
            {
                v.push_back(tmp->val);
                tmp = tmp->next;
            }
        }

        if (v.size() == 0)
            return NULL;

        sort(v.begin(), v.end());

        ListNode *head = new ListNode(v[0]);
        ListNode *tmp = head;

        for (int i = 1; i < v.size(); i++)
        {
            ListNode *t = new ListNode(v[i]);
            tmp->next = t;
            tmp = t;
        }
        return head;
    }
};

// Method - 2
// Convert merge k lists problem to merge 2 lists (k-1) times.
ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
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

ListNode *mergeKLists(vector<ListNode *> &v)
{
    if (v.size() == 0)
        return NULL;
    else if (v.size() == 1)
        return v[0];

    ListNode *head = mergeTwoLists(v[0], v[1]);

    for (int i = 2; i < v.size(); i++)
    {
        head = mergeTwoLists(head, v[i]);
    }

    return head;
}

// Method - 3
// Join all the K lists and sort the new list

// Method - 4
// Compare one by one
// Compare every k nodes (head of every linked list) and get the node with the smallest value.
// Extend the final sorted linked list with the selected nodes.

// Optimisation (use priority queue for getting minimum element)
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;

        ListNode *dummy = new ListNode(0);
        ListNode *h = dummy;
        priority_queue<pair<int, ListNode *>> q;

        for (int i = 0; i < lists.size(); i++)
            if (lists[i])
                q.push({lists[i]->val * -1, lists[i]});

        while (q.empty() == false)
        {
            ListNode *temp = q.top().second;

            q.pop();
            dummy->next = temp;
            dummy = temp;
            if (temp->next)
                q.push({temp->next->val * -1, temp->next});
        }
        return h->next;
    }
};