// https://leetcode.com/problems/insert-into-a-binary-search-tree/

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *root2 = root;
        while ((root))
        {
            if (root->val < val)
            {
                if (root->right)
                    root = root->right;
                else
                    break;
            }

            if (root->val > val)
            {
                if (root->left)
                    root = root->left;
                else
                    break;
            }
        }

        TreeNode *newnode = new TreeNode(val);
        if (!root2)
            return newnode;
        if (root->val > val)
            root->left = newnode;
        else
            root->right = newnode;

        return root2;
    }
};

// RECURSIVE SOLUTION
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);

        if (val > root->val)
            root->right = insertIntoBST(root->right, val);

        else
            root->left = insertIntoBST(root->left, val);

        return root;
    }
};