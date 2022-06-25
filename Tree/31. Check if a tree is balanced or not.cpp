// https://leetcode.com/problems/balanced-binary-tree/

// Method-1
int height(TreeNode *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
bool isBalanced(TreeNode *root)
{
    if (!root)
        return 1;
    int l1 = height(root->left);
    int l2 = height(root->right);
    int diff = abs(l1 - l2);
    if (diff <= 1)
        return (isBalanced(root->left) and isBalanced(root->right));
    return 0;
}

//Method-2

bool flag = 1;
int height(TreeNode *root)
{
    if (!root)
        return 0;
    int l1 = height(root->left);
    int l2 = height(root->right);
    if (abs(l1 - l2) > 1)
        flag = 0;
    return max(l1, l2) + 1;
}
bool isBalanced(TreeNode *root)
{
    if (!root)
        return 1;
    height(root);
    return flag;
}