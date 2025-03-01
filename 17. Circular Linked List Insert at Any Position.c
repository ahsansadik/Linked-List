#include<stdio.h>
#include<stdlib.h>

struct Node{
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
        printf("%d ",temp -> data);
        temp = temp->next;
    }
     printf("%d \n", temp -> data);
}

struct Node *insertAtPosition (struct Node *head, int data, int position)
{
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next=NULL;

    if(head==NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    if(position==1)
    {
        struct Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next=head;
        return newNode;

    }

    struct Node* temp = head;


    for(int i = 1; i  < position - 1  && temp -> next != head; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next=newNode;

    return head;
}


int main()
{
    struct Node *head = NULL;

    printList(head);

    head = insertAtPosition(head, 10, 1);
    printList(head);

    head = insertAtPosition(head, 15, 2);
    printList(head);

    head = insertAtPosition(head, 20, 3);
    printList(head);

    return 0;
}

