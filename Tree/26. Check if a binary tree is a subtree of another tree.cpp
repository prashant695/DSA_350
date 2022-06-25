// https://leetcode.com/problems/subtree-of-another-tree/

// Method 1 O(n^2) Solution

class Solution
{
public:
    bool flg = 0;
    bool same(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL && subRoot == NULL)
            return true;
        else if (root == NULL && subRoot != NULL)
            return false;
        else if (root != NULL && subRoot == NULL)
            return false;
        if (root->val != subRoot->val)
            return false;
        return same(root->left, subRoot->left) && same(root->right, subRoot->right);
    }
    bool dfs(TreeNode *root, TreeNode *subRoot)
    {
        if (root)
        {
            if (root->val == subRoot->val)
                if (same(root, subRoot))
                    flg = 1;
            dfs(root->left, subRoot);
            dfs(root->right, subRoot);
        }
        return 0;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        dfs(root, subRoot);
        return flg == 1;
    }
};

// Another approach (less time complexity but not accurate)
// Find pre and inorder of subtree
// Find pre and inorder of tree
// store the traversals in auxillary space (inS, inT, preS, preT) where S is subtree
// If inS is a subarray of inT and preS is a subarray of preT, return true otherwise false

// Drawback
// The above algorithm doesn't work for cases where a tree is present
// in another tree, but not as a subtree.
// However, although inS is a subarray of inT and preS is a subarray of preT,
// But the given tree would not be the subtree

// Method 2 O(N) solution

void StoreInorder(TreeNode *root, string &s)
{
    if (root == NULL)
    {
        s += '%';
        return;
    }
    StoreInorder(root->left, s);
    s += root->val + '0';
    StoreInorder(root->right, s);
}
void StorePreorder(TreeNode *root, string &s)
{
    if (root == NULL)
    {
        s += '%';
        return;
    }
    s += root->val + '0';
    StorePreorder(root->left, s);
    StorePreorder(root->right, s);
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (subRoot == NULL)
        return true;
    if (root == NULL)
        return false;
    string s1, s2, s3, s4;
    StoreInorder(root, s1);
    StoreInorder(subRoot, s2);
    StorePreorder(root, s3);
    StorePreorder(subRoot, s4);

    if (s1.find(s2) != std::string::npos)
    {
        if (s3.find(s4) != std::string::npos)
        {
            return true;
        }
    }
    return false;
}