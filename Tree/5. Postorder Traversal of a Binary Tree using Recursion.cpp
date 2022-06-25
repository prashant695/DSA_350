
// https://leetcode.com/problems/binary-tree-postorder-traversal/

// Time Complexity : O(n)
// Space Complexity : O(H)
class Solution
{
public:
    vector<int> v;
    void post(TreeNode *root)
    {
        if (root)
        {
            post(root->left);
            post(root->right);
            v.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        post(root);
        return v;
    }
};