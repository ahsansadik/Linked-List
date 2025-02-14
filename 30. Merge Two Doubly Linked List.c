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

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    head2->prev = temp;

    return head1;
}

int main() {
    struct Node *head1 = malloc(sizeof(struct Node));
    struct Node *two = malloc(sizeof(struct Node));
    struct Node *three = malloc(sizeof(struct Node));

    head1->data = 1;
    two->data = 2;
    three->data = 3;

    head1->next = two; head1->prev = NULL;
    two->next = three; two->prev = head1;
    three->next = NULL; three->prev = two;

    struct Node *head2 = malloc(sizeof(struct Node));
    struct Node *four = malloc(sizeof(struct Node));
    struct Node *five = malloc(sizeof(struct Node));

    head2->data = 4;
    four->data = 5;
    five->data = 6;

    head2->next = four; head2->prev = NULL;
    four->next = five; four->prev = head2;
    five->next = NULL; five->prev = four;

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    head1 = mergeLists(head1, head2);

    printf("Merged List: ");
    printList(head1);

    return 0;
}
