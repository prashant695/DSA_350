// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

// Method - 1
// Bruteforce
// Traverse the tree, store the nodes values in array, sort the array, return kth smallest
// TC: O(n logn)
// SC: O(n)

// Method - 2
// Inorder Traversal
// Traverse the tree, store the nodes values in array, return kth smallest
// TC: O(n)
// SC: O(n)

// Method - 3
// Morris Traversal
// Based on concept of threaded binary trees
// TC: O(n)
// SC: O(1)
// https://youtu.be/80Zug6D1_r4
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int res;
        int cnt = 0;

        TreeNode *cur = root;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                cnt++;
                if (cnt == k)
                    res = cur->val;
                cur = cur->right;
            }
            else
            {
                TreeNode *prev = cur->left;
                while (prev->right != NULL && prev->right != cur)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    prev->right = NULL;
                    cnt++;
                    if (cnt == k)
                        res = cur->val;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};

//
//
//
//
//
// Morris Traversal
vector<int> MorrisInorderTraversal(node *root)
{
    vector<int> inorder;

    node *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            node *prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
}
