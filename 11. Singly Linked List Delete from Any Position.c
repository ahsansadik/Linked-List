#include<stdio.h>
#include<stdlib.h>

struct node {

    int data;
    struct node *next;

};

void printList(struct node *head){
    if(head == NULL)
    {
        printf("Linked List is Empty\n");
    }

    while(head != NULL)
    {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}


struct node *deleteFromAnyPosition(struct node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    if (position == 1)
    {
        head = temp->next;
        free(temp);
        return head;
    }
    for (int i = 1; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Position out of bounds\n");
        return head;
    }

    struct node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
    return head;
}


int main()
{
    struct node *head;
    struct node *one = malloc(sizeof(struct node));
    struct node *two = malloc(sizeof(struct node));
    struct node *three = malloc(sizeof(struct node));

    head = one;

    one -> data = 1;
    one -> next = two;

    two -> data = 2;
    two -> next = three;

    three -> data = 3;
    three -> next = NULL;

    printList(head);

    head = deleteFromAnyPosition(head, 2);
    printList(head);

    return 0;
}

