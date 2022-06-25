
//  https://leetcode.com/problems/binary-tree-level-order-traversal/

// Time Complexity : O(n)
// Space Complexity : O(n) or O(2^h)
// Note: Maximum queue size would be 2^h, but 2^h is nearly equivalent to O(n)
// For skewed tree, maximum queue size would be o(1) (considering it to be the best case)

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        vector<int> v;
        vector<vector<int>> res;
        q.push(root);

        while (q.empty() == false)
        {
            int qu = q.size();
            v.clear();
            for (int i = 0; i < qu; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            res.push_back(v);
        }
        return res;
    }
};