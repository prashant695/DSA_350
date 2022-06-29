// https://leetcode.com/problems/validate-binary-search-tree/submissions/

// Method - 1
// Store the nodes in a vector while performing inorder traversal
// Then check for the conditions
// TC: O(n)
// SC: O(n)

// Method - 2
// TC: O(n)
// SC: O(1)
class Solution
{
public:
    bool ValidBST(TreeNode *root, TreeNode *&prev)
    {
        if (root)
        {
            if (!ValidBST(root->left, prev))
                return 0;

            if (prev != NULL and prev->val >= root->val)
                return 0;

            prev = root;

            return ValidBST(root->right, prev);
        }
        return 1;
    }
    bool isValidBST(TreeNode *root)
    {
        TreeNode *prev = NULL;
        return ValidBST(root, prev);
    }
};