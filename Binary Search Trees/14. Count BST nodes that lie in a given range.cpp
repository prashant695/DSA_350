// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

// Method - 1

class solution
{
public:
    int count = 0;
    void solve(Node *root, int l, int h)
    {
        if (root == NULL)
            return;
        if (root->data >= l and root->data <= h)
        {
            count++;
        }
        solve(root->left, l, h);
        solve(root->right, l, h);
    }
    int getCount(Node *root, int l, int h)
    {
        // your code goes here
        if (!root)
            return 0;
        solve(root, l, h);
        return count;
    }
};

// Method - 2
// TC: O(h + k) where k = no. of nodes in the given range
class Solution
{
public:
    int getCount(Node *root, int low, int high)
    {
        if (!root)
            return 0;

        if (root->data == high && root->data == low)
            return 1;

        if (root->data <= high && root->data >= low)
            return 1 + getCount(root->left, low, high) + getCount(root->right, low, high);

        else if (root->data < low)
            return getCount(root->right, low, high);

        else
            return getCount(root->left, low, high);
    }
};