// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#

Node *Head = NULL, *prev = NULL;
void dfs(Node *root)
{
    if (!root)
        return;
    dfs(root->left);

    if (!Head)
    {
        Head = root;
        prev = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
        prev = prev->right;
    }
    dfs(root->right);
}
Node *bToDLL(Node *root)
{
    dfs(root);
    return Head;
}