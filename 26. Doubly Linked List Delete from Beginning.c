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

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
    return head;
}

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *two = malloc(sizeof(struct Node));
    struct Node *three = malloc(sizeof(struct Node));

    head->data = 1;
    two->data = 2;
    three->data = 3;

    head->next = two; head->prev = NULL;
    two->next = three; two->prev = head;
    three->next = NULL; three->prev = two;

    printf("Original List: ");
    printList(head);

    head = deleteFromBeginning(head);

    printf("Updated List: ");
    printList(head);

    return 0;
}

