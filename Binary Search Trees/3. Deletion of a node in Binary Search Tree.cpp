
// https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1/#

// TC: O(h)
// For skewed tree, TC: O(n)

Node *FindMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
        return root;

    else if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        // Case 1:  No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 children
        else
        {
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}