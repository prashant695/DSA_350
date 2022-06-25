// https://leetcode.com/problems/binary-tree-right-side-view/

// Method - 1
// Level order Traversal
// Time Complexity : O(n)
// Space Complexity : O(n) or O(2^h)
// Note: Maximum queue size would be 2^h, but 2^h is nearly equivalent to O(n)
// For skewed tree, maximum queue size would be o(1) (considering it to be the best case)

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<int> res;
        while (q.empty() == false)
        {
            int qu = q.size();
            for (int i = 0; i < qu; i++)
            {
                TreeNode *c = q.front();
                q.pop();
                if (i == qu - 1)
                    res.push_back(c->val);
                if (c->left)
                    q.push(c->left);
                if (c->right)
                    q.push(c->right);
            }
        }
        return res;
    }
};

// Method - 2
// DFS
// Time Complexity : O(n)
// Space Complexity : O(h)
class Solution
{
public:
    vector<int> v;
    void dfs(TreeNode *root, int level)
    {
        if (root == NULL)
            return;
        if (v.size() == level)
            v.push_back(root->val);

        dfs(root->right, level + 1);
        dfs(root->left, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        dfs(root, 0);
        return v;
    }
};