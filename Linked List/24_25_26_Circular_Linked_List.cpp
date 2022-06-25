#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *first;

public:
    CircularLinkedList() { first = NULL; }
    CircularLinkedList(int A[], int n);

    void Display();
    int Length();
    void Insert(int index, int x);
    int Delete(int index);
};

CircularLinkedList::CircularLinkedList(int A[], int n)
{
    int i;
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = first;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void CircularLinkedList::Display()
{
    Node *h = first;
    do
    {
        cout << h->data << " ";
        h = h->next;
    } while (h != first);
    cout << endl;
}

int CircularLinkedList::Length()
{
    Node *p = first;
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != first);
    return len;
}
void CircularLinkedList::Insert(int index, int x)
{
    Node *t, *p = first;
    int i;
    if (index < 0 || index > Length())
        return;
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        if (first == NULL)
        {
            first = t;
            first->next = first;
        }
        else
        {
            while (p->next != first)
                p = p->next;
            p->next = t;
            t->next = first;
            first = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
int CircularLinkedList::Delete(int index)
{
    Node *q, *p = first;
    int i, x;
    if (index < 0 || index > Length())
        return -1;
    if (index == 1)
    {
        while (p->next != first)
            p = p->next;
        x = first->data;
        if (first == p)
        {
            delete (first);
            first = NULL;
        }
        else
        {
            p->next = first->next;
            delete (first);
            first = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete (q);
    }
    return x;
}
int main()
{
    int A[] = {2, 3, 4, 5, 6};
    CircularLinkedList l(A, 5);
    l.Delete(3);
    l.Display();
    return 0;
}
