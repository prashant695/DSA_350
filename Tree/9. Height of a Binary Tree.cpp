// https://leetcode.com/problems/maximum-depth-of-binary-tree

// Method - 1
// DFS
// Time Complexity : O(n)
// Space Complexity : O(h)

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// Method - 2
// BFS

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int cnt = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (q.empty() == false)
        {
            cnt++;
            int qu = q.size();
            for (int i = 0; i < qu; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        return cnt;
    }
};