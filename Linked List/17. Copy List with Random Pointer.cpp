// https://leetcode.com/problems/copy-list-with-random-pointer/

// Method - 1
// Using map
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, Node *> m;

        Node *h = head;
        while (h)
        {
            Node *t = new Node(h->val);
            m[h] = t;

            h = h->next;
        }

        for (auto it : m)
        {
            Node *original = it.first;
            Node *copy = it.second;

            copy->next = m[original->next];
            copy->random = m[original->random];
        }
        return m[head];
    }
};

// Method - 2
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        // step-1 creating a deep copy for every node
        Node *iter = head, *front = head, *copy;
        while (iter)
        {
            front = iter->next;
            copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }

        // step - 2 pointing random pointer of every deep copy
        iter = head;
        while (iter)
        {
            if (iter->random)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }

        // step - 3  differentiating deep copy list and original list
        iter = head;
        Node *psuedohead = new Node(0);
        copy = psuedohead;

        while (iter)
        {
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = iter->next;
        }

        return psuedohead->next;
    }
};

