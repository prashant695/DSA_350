// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1/

class Solution
{
public:
    Node *LCA(Node *root, int n1, int n2)
    {
        while (root)
        {
            if (n1 > root->data and n2 > root->data)
                root = root->right;

            else if (n1 < root->data and n2 < root->data)
                root = root->left;

            else
                return root;
        }
    }
};