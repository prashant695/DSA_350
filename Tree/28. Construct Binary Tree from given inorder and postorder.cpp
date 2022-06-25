// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution
{
public:
    int idx;
    map<int, int> m;
    TreeNode *create(vector<int> &pos, vector<int> &in, int i, int j)
    {
        if (i > j)
            return NULL;
        TreeNode *t = new TreeNode(pos[idx--]);
        t->right = create(pos, in, m[t->val] + 1, j);
        t->left = create(pos, in, i, m[t->val] - 1);
        return t;
    }
    TreeNode *buildTree(vector<int> &in, vector<int> &pos)
    {
        idx = in.size() - 1;
        for (int i = 0; i < in.size(); i++)
            m[in[i]] = i;
        TreeNode *root = create(pos, in, 0, in.size() - 1);
        return root;
    }
};