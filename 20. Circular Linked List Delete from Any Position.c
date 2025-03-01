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
        printf("%d  ",temp -> data);
        temp = temp->next;
    }
     printf("%d \n",temp -> data);
}

struct Node* deleteFromPosition(struct Node *head, int position)
{
    if (position == 1)
    {
        if (head->next == head)
        {
            free(head);
            return NULL;
        }

        struct Node *temp = head;
        struct Node *temp2 = head;

        while (temp2->next != head)
        {
            temp2 = temp2->next;
        }

        head = head->next;
        temp2->next = head;

        free(temp);
        return head;
    }

    struct Node *temp = head;
    struct Node *temp2 = NULL;

    for (int i = 1; i < position && temp->next != head; i++)
    {
        temp2 = temp;
        temp = temp->next;
    }

    if (temp->next == head && position > 1)
        return head;

    temp2->next = temp->next;
    free(temp);

    return head;
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
    three->next = head;

    printList(head);

    head = deleteFromPosition(head, 2);

    printList(head);

    return 0;
}

