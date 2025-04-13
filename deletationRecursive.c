struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Case 1: No children
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL || root->right == NULL)
        {
            struct Node* child = (root->left != NULL) ? root->left : root->right;
            free(root);
            return child;
        }

        // Case 3: Two children
        else
        {
            struct Node* successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }

    return root;
}
