// https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1/#

class Solution
{
public:
    int findMax(Node *root)
    {
        if (!root)
            return -1;

        if (root->right == NULL)
            return root->data;

        return findMax(root->right);
    }
    int findMin(Node *root)
    {
        if (!root)
            return -1;

        if (root->left == NULL)
            return root->data;

        return findMin(root->left);
    }
};