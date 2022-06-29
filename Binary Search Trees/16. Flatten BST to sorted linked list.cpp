// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Method - 1
// Recreate the BST from its in-order traversal
// TC: O(n)
// SC: O(n)

// Method - 2
// Change the linking of nodes while inorder traversal
// TC: O(n)
// SC: O(h)

// Method - 3
// Morris Traversal
// TC: O(n)
// SC: O(1)
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;

        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left)
            {
                TreeNode *pre = curr->left;
                while (pre->right)
                {
                    pre = pre->right;
                }
                pre->right = curr->right;

                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};