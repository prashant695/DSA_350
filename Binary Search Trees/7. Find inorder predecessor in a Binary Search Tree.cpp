// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1/

class Solution
{
public:
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        Node *ans = nullptr;
        while (root)
        {
            if (x->data <= root->data)
                root = root->left;

            else
            {
                ans = root;
                root = root->right;
            }
        }

        return ans;
    }
};

// Finding predecessor and successor in a BST
class solution
{
    void findPreSuc(Node *root, Node *&pre, Node *&succ, int key)
    {
        if (root == NULL)
            return;

        findPreSuc(root->left, pre, succ, key);

        if (root->key < key)
            pre = root;

        if (succ == NULL && root->key > key)
            succ = root;

        findPreSuc(root->right, pre, succ, key);
    }
};