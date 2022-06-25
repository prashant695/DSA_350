// https://leetcode.com/problems/cousins-in-binary-tree/

// Method - 1
// DFS

class Solution
{
public:
    int par_x, par_y, dep_x = -1, dep_y = -1;
    void dfs(TreeNode *root, int depth, int parent, int x, int y)
    {
        if (root)
        {
            if (root->val == x)
            {
                par_x = parent;
                dep_x = depth;
            }
            else if (root->val == y)
            {
                par_y = parent;
                dep_y = depth;
            }
            else if (dep_x != -1 and dep_y != -1)
                return;
            dfs(root->left, depth + 1, root->val, x, y);
            dfs(root->right, depth + 1, root->val, x, y);
        }
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        dfs(root, 0, -1, x, y);
        return dep_x == dep_y and par_x != par_y;
    }
};

// Method - 2
// BFS
// Time Complexity : O(n)
// Space Complexity : O(n) or O(2^h)
// Note: Maximum queue size would be 2^h, but 2^h is nearly equivalent to O(n)
// For skewed tree, maximum queue size would be o(1) (considering it to be the best case)

class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        queue<TreeNode *> q;
        q.push(root);
        int cnt = 0;

        while (q.empty() == false)
        {
            int qu = q.size();
            cnt = 0;
            for (int i = 0; i < qu; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left and curr->right)
                {
                    if (curr->left->val == x and curr->right->val == y)
                        return 0;
                    if (curr->left->val == y and curr->right->val == x)
                        return 0;
                }
                if (curr->val == x or curr->val == y)
                    cnt++;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            if (cnt == 1)
                return 0;
            else if (cnt == 2)
                return 1;
        }
        return 0;
    }
};

// ALTERNATE VERSION

// Method-1
// Time Complexity : O(n)
// Space Complexity : O(h)
bool is_siblings(TreeNode *root, int x, int y)
{
    if (!root)
        return 0;
    if (root->left and root->right)
    {
        if (root->left->val == x and root->right->val == y)
            return 1;
        if (root->left->val == y and root->right->val == x)
            return 1;
    }
    return is_siblings(root->left, x, y) or is_siblings(root->right, x, y);
}
int level(TreeNode *root, int val, int k)
{
    if (!root)
        return 0;

    if (root->val == val)
        return k;

    return max(level(root->left, val, k + 1), level(root->right, val, k + 1));
}
bool isCousins(TreeNode *root, int x, int y)
{
    return level(root, x, 0) == level(root, y, 0) and !(is_siblings(root, x, y));
}
