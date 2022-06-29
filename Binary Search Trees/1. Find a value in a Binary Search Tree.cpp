// https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1/

// TC: O(h)
// For skewed tree, TC: O(n)
// SC: O(1)

class solution
{
    bool search(Node *root, int x)
    {
        while (root)
        {
            if (root->data == x)
                return 1;

            else if (root->data < x)
                root = root->right;

            else
                root = root->left;
        }
        return 0;
    }
};

// RECURSIVE SOLUTION
// https://leetcode.com/problems/search-in-a-binary-search-tree/

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return NULL;
        else if (root->val == val)
            return root;
        else if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};
