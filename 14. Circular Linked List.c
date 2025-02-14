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

    return 0;
}
