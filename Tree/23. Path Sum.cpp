// https://leetcode.com/problems/path-sum/

// Time complexity -> O(n)
// Space complexity -> O(h)

class Solution
{
public:
    bool check(TreeNode *root, int targetSum, int s)
    {
        if (!root)
            return false;
        s += root->val;
        if (!root->left and !root->right and s == targetSum)
            return true;
        return check(root->left, targetSum, s) or check(root->right, targetSum, s);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return check(root, targetSum, 0);
    }
};