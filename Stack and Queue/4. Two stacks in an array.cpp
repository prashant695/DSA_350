// Both stacks should use the same array for storing the elements

// Method - 1
// Divide the array into equal halves i.e. one half for stack1 and other for stack2
// Use a[0] --- a[n/2] for stack1
// Use a[n/2+1] --- a[n-1] for stack2

// However, This method is space inefficient as if array size is 8
// and 4 elements are already been pushed to stack1 and 0 to stack2
// Incase we try to push another element to stack1, result would be stack overflow
// Even if there is space for 4 more elements

// Solution
// Stack1 should start from left extreme of array and
// Stack2 should start from right extreme of array

//   | 2 |--|--|--|--|--|--|--|     Push 2 to stack1

//   | 2 |--|--|--|--|--|--| 8 |    Push 8 to stack2

//   | 2 | 7 |--|--|--|--|--| 8 |   Push 7 to stack1

//   | 2 | 7 |--|--|--|--| 5 | 8 |   Push 5 to stack2

// Function to push an integer into the stack1.
int size = 100;
int st[100];
int top1 = 0, top2 = 99;
void twoStacks ::push1(int x)
{
    st[top1++] = x;
}

// Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    st[top2--] = x;
}

// Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if ((top1) == -1)
        return -1;
    return st[--top1];
}

// Function to remove an element from top of the stack2.
int twoStacks ::pop2()
{
    if ((top2) == size)
        return -1;
    return st[++top2];
}