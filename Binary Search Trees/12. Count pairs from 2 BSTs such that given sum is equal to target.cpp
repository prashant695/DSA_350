// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1/

// Method - 1
// For every node n in bst1, check for sum - n in bst2
// TC: O(n1 * h2)
// SC: O(1)

class Solution
{
public:
    int cnt = 0;
    bool search(Node *root, int x)
    {
        int flg = 0;
        while (root)
        {
            if (root->data == x)
            {
                flg = 1;
                break;
            }
            else if (root->data < x)
            {
                root = root->right;
            }
            else
                root = root->left;
        }
        return flg;
    }

    void inorder(Node *root1, Node *root2, int x)
    {
        if (root1)
        {
            inorder(root1->left, root2, x);
            if (search(root2, x - root1->data))
                cnt++;
            inorder(root1->right, root2, x);
        }
    }
    int countPairs(Node *root1, Node *root2, int x)
    {
        inorder(root1, root2, x);
        return cnt;
    }
};

// Method - 2
// Traverse BST 1 from smallest value to node to largest
// Traverse BST 2 from largest value node to smallest.
// Perform these two traversals simultaneously
// Sum up the corresponding node’s value
// If sum == x, then increment count
//  If x > sum, then move to the inorder successor of the current node of BST 1
//  else move to the inorder predecessor of the current node of BST 2
// TC: O(n1 + n2)
// SC: O(h1 + h2)
int countPairs(Node *root1, Node *root2, int x)
{
    if (root1 == NULL || root2 == NULL)
        return 0;

    stack<Node *> st1, st2;
    Node *top1, *top2;

    int count = 0;

    while (1)
    {
        while (root1 != NULL)
        {
            st1.push(root1);
            root1 = root1->left;
        }

        while (root2 != NULL)
        {
            st2.push(root2);
            root2 = root2->right;
        }

        if (st1.empty() || st2.empty())
            break;

        top1 = st1.top();
        top2 = st2.top();

        if ((top1->data + top2->data) == x)
        {
            count++;

            st1.pop();
            st2.pop();

            root1 = top1->right;
            root2 = top2->left;
        }

        else if ((top1->data + top2->data) < x)
        {
            st1.pop();
            root1 = top1->right;
        }

        else
        {
            st2.pop();
            root2 = top2->left;
        }
    }

    return count;
}