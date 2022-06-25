
// https://practice.geeksforgeeks.org/problems/queue-reversal/1/

queue<int> rev(queue<int> Queue)
{
    stack<int> Stack;
    while (!Queue.empty())
    {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty())
    {
        Queue.push(Stack.top());
        Stack.pop();
    }

    return Queue;
}