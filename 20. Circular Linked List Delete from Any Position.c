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

struct Node* deleteFromPosition(struct Node *head, int position)
{
    if (head == NULL)
        return NULL;

    if (position == 1)  // If deleting the first node
    {
        if (head->next == head)  // Only one node in the list
        {
            free(head);
            return NULL;
        }

        struct Node *temp = head;
        struct Node *last = head;

        while (last->next != head)  // Find last node
        {
            last = last->next;
        }

        head = head->next;  // Move head to next node
        last->next = head;  // Update last node's next pointer

        free(temp);  // Delete old head
        return head;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    for (int i = 1; i < position && temp->next != head; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == head && position > 1)  // If position is out of range
        return head;

    prev->next = temp->next;  // Bypass the node
    free(temp);  // Delete the node

    return head;
}

int main()
{
    struct Node *head = NULL;
    struct Node *one = NULL;
    struct Node *two = NULL;
    struct Node *three = NULL;
    struct Node *four = NULL;

    one = malloc(sizeof(struct Node));
    two = malloc(sizeof(struct Node));
    three = malloc(sizeof(struct Node));
    four = malloc(sizeof(struct Node));

    one->data = 1;
    two->data = 2;
    three->data = 3;
    four->data = 4;

    head = one;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = head; // Making it circular

    printList(head);

    head = deleteFromPosition(head, 2);  // Delete node at position 2

    printList(head);

    return 0;
}
