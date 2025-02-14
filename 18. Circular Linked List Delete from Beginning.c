#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    while(temp->next != head)
    {
        printf("%d -> ",temp -> data);
        temp = temp->next;
    }
     printf("%d (head)\n",temp -> data);
}

struct Node* deleteFromBeginning(struct Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == head)  // If only one node is present
    {
        free(head);
        return NULL;
    }

    struct Node *temp = head;
    struct Node *last = head;

    while (last->next != head)  // Find the last node
    {
        last = last->next;
    }

    head = head->next;  // Move head to the next node
    last->next = head;  // Update last node's next pointer

    free(temp);  // Delete old head

    return head;  // Return the new head
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

    printList(head);

    head = deleteFromBeginning(head);  // Delete first node

    printList(head);

    head = deleteFromBeginning(head);  // Delete first node

    printList(head);

    return 0;
}

