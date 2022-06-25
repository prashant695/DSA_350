// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#


class Solution
{
public:
    int solve(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = solve(root->left);
        int right = solve(root->right);
        int root = root->val;
        root->val = left + right;

        return left + right + root;
    }

    int SumTree(TreeNode *root)
    {
        return solve(root);
    }
};