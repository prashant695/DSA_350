// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> map;
        queue<pair<TreeNode *, pair<int, int>>> queue;
        queue.push({root, {0, 0}});

        while (!queue.empty())
        {
            auto p = queue.front();
            queue.pop();
            TreeNode *curr = p.first;
            int x = p.second.first, y = p.second.second;

            map[x][y].insert(curr->val);

            if (curr->left)
            {
                queue.push({curr->left, {x - 1, y + 1}});
            }
            if (curr->right)
            {
                queue.push({curr->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : map)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};