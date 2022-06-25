// METHOD - 1
// Using Array

#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void Display();
};
void Queue::enqueue(int x)
{
    if (rear == size - 1)
        printf("Queue Full\n");
    else
    {
        rear++;
        Q[rear] = x;
    }
}
int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
        printf("Queue is Empty\n");
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}
void Queue::Display()
{
    for (int i = front + 1; i <= rear; i++)
        printf("%d ", Q[i]);
    printf("\n");
}
int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.Display();
    return 0;
}

// METHOD - 2
// Using Linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front, *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x);
    int dequeue();
    void Display();
};
void Queue::enqueue(int x)
{
    Node *t;
    t = new Node;
    if (t == NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int Queue::dequeue()
{
    int x = -1;
    Node *t;
    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete (t);
    }
    return x;
}
void Queue::Display()
{
    Node *p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.Display();
    printf("%d ", q.dequeue());
    return 0;
}