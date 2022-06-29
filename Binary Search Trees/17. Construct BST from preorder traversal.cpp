// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/

// Method - 1
// insert the node one by one to BST
// TC: o(n * n)  Case for left skewed tree
// SC: O(1)
class Solution
{
public:
    TreeNode *root;
    void insert(int x)
    {
        TreeNode *temp = root, *prev = root;
        while (temp)
        {
            prev = temp;
            if (x < temp->val)
                temp = temp->left;
            else
                temp = temp->right;
        }

        TreeNode *node = new TreeNode(x);
        if (x < prev->val)
            prev->left = node;
        else
            prev->right = node;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *t = new TreeNode(preorder[0]);
        root = t;
        for (int i = 1; i < preorder.size(); i++)
            insert(preorder[i]);
        return root;
    }
};

// Method - 2
// Obtain the inorder traversal, construct the tree using pre and in order
// TC: O(n logn)(Sorting) + O(n)(constructing tree)
// SC: O(n)
class Solution
{
public:
    int idx = 0;
    map<int, int> m;
    TreeNode *build(vector<int> &pre, vector<int> &inorder, int i, int j)
    {
        if (i > j)
            return NULL;

        TreeNode *t = new TreeNode(pre[idx++]);

        t->left = build(pre, inorder, i, m[t->val] - 1);
        t->right = build(pre, inorder, m[t->val] + 1, j);

        return t;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());

        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;

        TreeNode *root = build(preorder, inorder, 0, in.size() - 1);
        return root;
    }
};

// Method - 3
// https://youtu.be/UmJT3j26t1I
// TC: O(3n)
// SC: O(1)
class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &A)
    {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode *build(vector<int> &A, int &i, int bound)
    {
        if (i == A.size() || A[i] > bound)
            return NULL;
        TreeNode *root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
};