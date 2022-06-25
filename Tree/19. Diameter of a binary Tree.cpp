// https://leetcode.com/problems/diameter-of-binary-tree/

// Method - 1
// O(n2)

class Solution
{
public:
    int res = -1;
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int temp = (depth(root->left) + depth(root->right));
        res = max(res, temp);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return res;
    }
};

// Method - 2
// O(n)

class Solution
{
public:
    int depth(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;

        int left_height = depth(root->left, ans);
        int right_height = depth(root->right, ans);

        ans = max(ans, left_height + right_height);

        return 1 + max(left_height, right_height);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = INT_MIN;
        depth(root, ans);

        return ans;
    }
};