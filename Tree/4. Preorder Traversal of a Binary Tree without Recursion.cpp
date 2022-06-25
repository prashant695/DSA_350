// https://leetcode.com/problems/binary-tree-preorder-traversal/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        stack<TreeNode *> st;
        st.push(root);
        
        vector<int> res;
        
        while (!st.empty())
        {
            TreeNode *curr = st.top();
            res.push_back(curr->val);
            st.pop();

            if (curr->right)
                st.push(curr->right);
                
            if (curr->left)
                st.push(curr->left);
        }
        return res;
    }
};