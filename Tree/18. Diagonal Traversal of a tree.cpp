// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

class Solution
{
public:
    vector<int> diagonal(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        vector<int> res;
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            while (curr)
            {
                if (curr->left)
                    q.push(curr->left);
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
        return res;
    }
};