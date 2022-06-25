// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1#


// Time complexity -> O(n)
// Space complexity -> O(h)

class Solution
{
public:
    bool dfs(Treenode *root, int level, int leaflevel)
    {
        if (!root)
            return 1;
        if (!root->left and !root->right)
        {
            if (leaflevel == 0)
            {
                leaflevel = level;
                return 1;
            }

            return leaflevel == level;
        }

        return dfs(root->left, level + 1, leaflevel) and dfs(root->right, level + 1, leaflevel);
    }

    bool samelevel(TreeNode *root)
    {
        return dfs(root, 0, 0);
    }
};
