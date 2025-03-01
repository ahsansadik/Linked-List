#include<stdio.h>
#include<stdlib.h>

struct node {

    int data;
    struct node *next;
    struct node *prev;

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

struct node *insertAtAnyPosition(struct node *head, int data, int position)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode -> data = data;

    if(position == 1)
    {
        newNode -> next = head;
        head = newNode;
        return head;
    }

    struct node *temp = head;

    for (int i = 1; temp != NULL && i < position - 1 ; i++)
    {
        temp = temp -> next;
    }

    if (temp == NULL)
    {
        printf("out of bound\n");
        free(newNode);
        return head;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;

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
    head = insertAtAnyPosition(head, 0, 4);
    printList(head);

    return 0;
}

