// https://leetcode.com/problems/balance-a-binary-search-tree/submissions/

// Method
// Store the Inorder Traversal and Construct the tree accordingly
// TC: O(n)
// SC: O(n)
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (root)
        {
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
    }
    TreeNode *balance(vector<int> &v, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;

        TreeNode *node = new TreeNode(v[mid]);

        node->left = balance(v, start, mid - 1);
        node->right = balance(v, mid + 1, end);

        return node;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> v;
        inorder(root, v);

        return balance(v, 0, v.size() - 1);
    }
};