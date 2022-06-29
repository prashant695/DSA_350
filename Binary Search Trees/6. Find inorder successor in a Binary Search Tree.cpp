// https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1/#

class Solution
{
public:
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        Node *ans = nullptr;
        while (root)
        {
            if (x->data >= root->data)
                root = root->right;

            else
            {
                ans = root;
                root = root->left;
            }
        }

        return ans;
    }
};
