// https://leetcode.com/problems/construct-string-from-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void pre(TreeNode *root, string &s)
    {
        if (root)
        {
            s += to_string(root->val);
            if (root->left)
            {
                s += '(';
                pre(root->left, s);
                s += ')';
            }
            else if (root->right)
                s += "()";

            if (root->right)
            {
                s += '(';
                pre(root->right, s);
                s += ')';
            }
        }
    }
    string tree2str(TreeNode *root)
    {
        string s = "";
        pre(root, s);
        return s;
    }
};