#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insertAtPosition(struct Node* head, int newData, int position)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = newData;

    if (position == 1) {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) head->prev = newNode;
        return newNode;
    }

    struct Node* temp = head;

    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL) return head;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

int main() {
    struct Node *head = NULL, *one = NULL, *two = NULL, *three = NULL;

    one = malloc(sizeof(struct Node));
    two = malloc(sizeof(struct Node));
    three = malloc(sizeof(struct Node));

    one->data = 1;
    two->data = 2;
    three->data = 3;
    head = one;

    one->next = two;
    one->prev = NULL;
    two->next = three;
    two->prev = one;
    three->next = NULL;
    three->prev = two;

    printf("Original List: ");
    printList(head);

    head = insertAtPosition(head, 4, 2);

    printf("Updated List: ");
    printList(head);

    return 0;
}
