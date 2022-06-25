
// https://leetcode.com/problems/binary-tree-postorder-traversal/

// Method - 1
// Pre - order Reversal
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        stack<TreeNode *> st;

        if (root == NULL)
            return {};

        st.push(root);

        while (st.empty() == false)
        {
            TreeNode *curr = st.top();
            v.push_back(curr->val);
            st.pop();
            if (curr->left)
                st.push(curr->left);
            if (curr->right)
                st.push(curr->right);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

// Method - 2
vector<int> postorderTraversal(TreeNode *root)
{
    if (!root)
        return {};
    stack<TreeNode *> st;
    st.push(root);
    vector<int> res;
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        if (!curr->left and !curr->right)
        {
            res.push_back(curr->val);
            st.pop();
        }
        else if (curr->right)
        {
            st.push(curr->right);
            curr->right = NULL;
        }
        if (curr->left)
        {
            st.push(curr->left);
            curr->left = NULL;
        }
    }
    return res;
}