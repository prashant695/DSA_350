// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

// Method-1 (using Reverse())
// Time Complexity : O(n)
// Space Complexity : O(n)
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    if (root == NULL)
        return {};
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> res;
    while (!q.empty())
    {
        vector<int> v;
        int qu = q.size();
        for (int i = 0; i < qu; i++)
        {
            TreeNode *root = q.front();
            q.pop();
            v.push_back(root->val);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        res.push_back(v);
    }
    reverse(res.begin(), res.end());
    return res;
}

// Method-2 (using Stack)
// Time Complexity : O(n)
// Space Complexity : O(2*n)
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    if (!root)
        return {};
    queue<TreeNode *> q;
    stack<vector<int>> st;
    q.push(root);
    vector<vector<int>> res;
    while (!q.empty())
    {
        vector<int> v;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *root = q.front();
            q.pop();
            v.push_back(root->val);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        st.push(v);
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

// Method-3 (By first calculating number of Levels)
// Time Complexity : O(n)
// Space Complexity : O(n) or O(2^h)
// Note: Maximum queue size would be 2^h, but 2^h is nearly equivalent to O(n)
// For skewed tree, maximum queue size would be o(1) (considering it to be the best case)

int dfs(TreeNode *root)
{
    if (!root)
        return 0;
    return max(dfs(root->left), dfs(root->right)) + 1;
}
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    if (!root)
        return {};
    queue<TreeNode *> q;
    q.push(root);
    int k = dfs(root);
    vector<vector<int>> res(k);
    k--;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *root = q.front();
            q.pop();
            res[k].push_back(root->val);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        k--;
    }
    return res;
}