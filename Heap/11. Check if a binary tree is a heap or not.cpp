// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1/
// Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

class Solution
{
public:
    bool isCompleteTree(struct Node *root)
    {
        queue<struct Node *> q;
        q.push(root);
        int flg = 0;

        while (q.empty() == false)
        {
            int qu = q.size();
            for (int i = 0; i < qu; i++)
            {
                struct Node *temp = q.front();
                q.pop();

                if (temp == NULL)
                {
                    flg = 1;
                    continue;
                }
                else if (flg == 1)
                    return 0;

                if (temp->left and temp->data < temp->left->data)
                    return 0;
                if (temp->right and temp->data < temp->right->data)
                    return 0;

                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return 1;
    }

    bool isHeap(struct Node *tree)
    {
        return isCompleteTree(tree);
    }
};