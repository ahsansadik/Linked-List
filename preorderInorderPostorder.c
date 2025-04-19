void preorder(struct node* current)
{
    if(current == NULL) return;
    printf("%d ", current->data);
    preorder(current->left);
    preorder(current->right);
}

void inorder(struct node* current)
{
    if(current == NULL) return;
    inorder(current->left);
    printf("%d ", current->data);
    inorder(current->right);
}

void postorder(struct node* current)
{
    if(current == NULL) return;
    postorder(current->left);
    postorder(current->right);
    printf("%d ", current->data);
}
