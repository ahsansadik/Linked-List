#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int searchNode(struct Node *head, int key)
{
    if (head == NULL)
        return 0;

    struct Node *temp = head;
    do
    {
        if (temp->data == key)
            return 1;  // Node found
        temp = temp->next;
    } while (temp != head);

    return 0;  // Node not found
}

int main()
{
    struct Node *head = NULL;
    struct Node *one = NULL;
    struct Node *two = NULL;
    struct Node *three = NULL;

    one = malloc(sizeof(struct Node));
    two = malloc(sizeof(struct Node));
    three = malloc(sizeof(struct Node));

    one->data = 1;
    two->data = 2;
    three->data = 3;

    head = one;

    one->next = two;
    two->next = three;
    three->next = head; // Making it circular

    int key = 2;
    if (searchNode(head, key))
        printf("Node with value %d found.\n", key);
    else
        printf("Node with value %d not found.\n", key);

    return 0;
}
