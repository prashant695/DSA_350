// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

class Solution
{
public:
    void left(Node *root, vector<int> &res)
    {
        if (!root)
            return;
        if (root->left)
        {
            res.push_back(root->data);
            left(root->left, res);
        }
        else if (root->right)
        {
            res.push_back(root->data);
            left(root->right, res);
        }
    }
    void leaf(Node *root, vector<int> &res)
    {
        if (!root)
            return;
        leaf(root->left, res);
        if (!root->left and !root->right)
            res.push_back(root->data);
        leaf(root->right, res);
    }
    void right(Node *root, vector<int> &res)
    {
        if (!root)
            return;

        if (root->right)
        {
            right(root->right, res);
            res.push_back(root->data);
        }
        else if (root->left)
        {
            right(root->left, res);
            res.push_back(root->data);
        }
    }
    vector<int> boundary(Node *root)
    {
        vector<int> res;
        res.push_back(root->data);
        left(root->left, res);
        leaf(root, res);
        right(root->right, res);
        return res;
    }
}: