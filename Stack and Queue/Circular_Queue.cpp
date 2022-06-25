
#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    CircularQueue()
    {
        front = rear = 0;
        size = 10;
        Q = new int[size];
    }
    CircularQueue(int size)
    {
        front = rear = 0;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void Display();
};
void CircularQueue::enqueue(int x)
{
    if ((rear + 1) % size == front)
        printf("Queue is Full");
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}
int CircularQueue::dequeue()
{
    int x = -1;
    if (front == rear)
        printf("Queue is Empty\n");
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}
void CircularQueue::Display()
{
    int i = front + 1;
    do
    {
        printf("%d ", Q[i]);
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    printf("\n");
}
int main()
{
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.Display();
    return 0;
}
