#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void searchNode(struct Node *head, int key)
{
    struct Node *temp = head;
    int position = 0;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list\n", key);
}

int main()
{
    struct Node *head = NULL;
    struct Node *one = malloc(sizeof(struct Node));
    struct Node *two = malloc(sizeof(struct Node));
    struct Node *three = malloc(sizeof(struct Node));

    one->data = 1; one->next = two;
    two->data = 2; two->next = three;
    three->data = 3; three->next = NULL;
    head = one;

    printList(head);

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    searchNode(head, key);

    return 0;
}
