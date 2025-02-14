#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *insertAtPosition (struct Node* head, int data, int position)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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
    int count = 1;

    while(count  < position - 1  && temp -> next != head)
    {
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    temp->next=newNode;
    return head;
}

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
    head = insertAtPosition(head, 10, 1);
    head = insertAtPosition(head, 15, 2);
    head = insertAtPosition(head, 20, 3);

    printf("Circular Linked List\n");

    printList(head);

    return 0;
}
