#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value)
{
    struct Node* newNode = createNode(value);
    if (root == NULL) return newNode;

    struct Node* parent = NULL;
    struct Node* current = root;

    while (current != NULL)
    {
        parent = current;
        if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

struct Node* findMin(struct Node* node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

struct Node* deleteNode(struct Node* root, int key)
{
    struct Node* parent = NULL;
    struct Node* current = root;


    while (current != NULL && current->data != key)
    {
        parent = current;
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }


    if (current == NULL) return root;


// Case 1: Node has no children (leaf node)
    if (current->left == NULL && current->right == NULL)
    {
        if (current == root) root = NULL;
        else if (parent->left == current) parent->left = NULL;
        else parent->right = NULL;
        free(current);
    }

// Case 2: Node has one child
    else if (current->left == NULL || current->right == NULL)
    {
        struct Node* child = (current->left != NULL) ? current->left : current->right;
        if (current == root) root = child;
        else if (parent->left == current) parent->left = child;
        else parent->right = child;
        free(current);
    }

// Case 3: Node has two children
    else
    {
        struct Node* successor = findMin(current->right);
        int successorData = successor->data;
        root = deleteNode(root, successor->data);
        current->data = successorData;
    }

    return root;
}


void inorder(struct Node* root)
{
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}


int main()
{
    struct Node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);


    for (int i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
    }

    printf("Inorder Traversal before deletion: ");
    inorder(root);
    printf("\n");


    int key = 50;
    root = deleteNode(root, key);

    printf("Inorder Traversal after deleting %d: ", key);
    inorder(root);
    printf("\n");

    return 0;
}
