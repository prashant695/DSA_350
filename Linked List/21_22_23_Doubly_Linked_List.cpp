#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
private:
    Node *first;

public:
    DoublyLinkedList() { first = NULL; }
    DoublyLinkedList(int A[], int n);
    ~DoublyLinkedList();

    void Display();
    int Length();
    void Insert(int index, int x);
    int Delete(int index);
    void Reverse();
};
DoublyLinkedList::DoublyLinkedList(int A[], int n)
{
    Node *t, *last;
    int i;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
DoublyLinkedList::~DoublyLinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
void DoublyLinkedList::Display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int DoublyLinkedList::Length()
{
    Node *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
void DoublyLinkedList::Insert(int index, int x)
{
    Node *p = first;
    Node *t;
    int i;
    if (index < 0 || index > Length())
        return;
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}
int DoublyLinkedList::Delete(int index)
{
    Node *p = first;
    int x = -1, i;
    if (index < 1 || index > Length())
        return -1;
    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        delete (p);
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete (p);
    }
    return x;
}
void DoublyLinkedList::Reverse()
{
    Node *p = first;
     Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            first = p;
    }
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    DoublyLinkedList l(A, 5);
    l.Reverse();
    l.Display();
    return 0;
}

