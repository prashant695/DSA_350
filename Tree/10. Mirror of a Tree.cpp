// Given the root of a binary tree, invert(mirror) the tree, and return its root.
// https://leetcode.com/problems/invert-binary-tree/

// APPROACH-1 (using recursion)

// Time Complexity : O(n)
// Space Complexity : O(h)
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root)
        {
            swap(root->left, root->right);

            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};

// APPROACH-2 (using Stack)

// Time Complexity : O(n)
// Space Complexity : O(n)

TreeNode *invertTree(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *p = st.top();
        st.pop();
        if (p)
        {
            st.push(p->left);
            st.push(p->right);
            swap(p->left, p->right);
        }
    }
    return root;
}
