// https://leetcode.com/problems/binary-tree-preorder-traversal/

// Time Complexity : O(n)
// Space Complexity : O(h)

class Solution
{
public:
    vector<int> v;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root)
        {
            v.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return v;
    }
};