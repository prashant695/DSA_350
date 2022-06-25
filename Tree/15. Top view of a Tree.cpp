// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, map<int, multiset<int>>> map;
        queue<pair<Node *, pair<int, int>>> queue;
        queue.push({root, {0, 0}});

        while (!queue.empty())
        {
            auto p = queue.front();
            queue.pop();
            Node *curr = p.first;
            int x = p.second.first, y = p.second.second;

            map[x][y].insert(curr->data);

            if (curr->left)
            {
                queue.push({curr->left, {x - 1, y + 1}});
            }
            if (curr->right)
            {
                queue.push({curr->right, {x + 1, y + 1}});
            }
        }
        vector<int> ans;
        for (auto p : map)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col[0]);
        }
        return ans;
    }
};

// ALTERNATE VERSION

// Method-1 BFS (vertical level order traversal)

vector<int> topView(Node *root)
{
    vector<int> res;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        Node *curr = x.first;
        int i = x.second;
        if (mp.find(i) == mp.end())
            mp[i] = curr->data;
        if (curr->left)
        {
            q.push({curr->left, i - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, i + 1});
        }
    }
    for (auto i : mp)
    {
        res.push_back(i.second);
    }
    return res;
}