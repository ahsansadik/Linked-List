#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

int searchNode(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) return position;
        temp = temp->next;
        position++;
    }
    return -1;
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

    int key = 2;
    int position = searchNode(head, key);

    if (position != -1)
        printf("Node %d found at position %d\n", key, position);
    else
        printf("Node %d not found\n", key);

    return 0;
}
