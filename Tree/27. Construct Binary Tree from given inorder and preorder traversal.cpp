// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution
{
public:
    int idx = 0;
    map<int, int> m;
    TreeNode *create(vector<int> &pre, vector<int> &in, int i, int j)
    {
        if (i > j)
            return NULL;
        TreeNode *t = new TreeNode(pre[idx++]);
        t->left = create(pre, in, i, m[t->val] - 1);
        t->right = create(pre, in, m[t->val] + 1, j);
        return t;
    }

    TreeNode *buildTree(vector<int> &pre, vector<int> &in)
    {
        for (int i = 0; i < in.size(); i++)
            m[in[i]] = i;
        TreeNode *root = create(pre, in, 0, in.size() - 1);
        return root;
    }
};