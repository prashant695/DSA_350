// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    map<int, Node *> m;
    void dfs(Node *node)
    {
        if (!m[node->val])
        {
            Node *obj = new Node(node->val);
            m[node->val] = obj;

            for (auto x : node->neighbors)
            {
                dfs(x);
                m[node->val]->neighbors.push_back(m[x->val]);
            }
        }
    }
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        dfs(node);
        return m[node->val];
    }
};