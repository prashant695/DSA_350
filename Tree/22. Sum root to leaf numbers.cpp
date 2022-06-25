// https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution
{
public:
    int res = 0;
    void solve(TreeNode *root, int val)
    {
        if (root)
        {
            val = val * 10 + root->val;
            if (root->left == nullptr and root->right == nullptr)
            {
                res += val;
                return;
            }

            solve(root->left, val);
            solve(root->right, val);
        }
    }
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        solve(root, 0);
        return res;
    }
};