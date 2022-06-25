// https://leetcode.com/problems/minimum-depth-of-binary-tree/

// DFS
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        if (root->left == NULL)
            return minDepth(root->right) + 1;
        if (root->right == NULL)
            return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

//
class Solution
{
public:
    int res = INT_MAX;
    ;
    int dfs(TreeNode *root, int curr_level)
    {
        if (root)
        {
            if (!root->left and !root->right)
                if (curr_level < res)
                    res = curr_level;

            dfs(root->left, curr_level + 1);
            dfs(root->right, curr_level + 1);
        }
        return res;
    }
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int res = dfs(root, 1);
        return res;
    }
};

// ALTERNATE VERSIOM

// Time complexity -> O(n)
// Space complexity -> O(h)
int mi = INT_MAX;
void dfs(TreeNode *root, int k)
{
    if (!root)
        return;
    if (!root->left and !root->right)
    {
        mi = min(mi, k);
        return;
    }
    dfs(root->left, k + 1);
    dfs(root->right, k + 1);
}
int minDepth(TreeNode *root)
{
    if (!root)
        return 0;
    dfs(root, 1);
    return mi;
}