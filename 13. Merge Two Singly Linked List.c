#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void printList(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct Node* concatenateLists(struct Node *head1, struct Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;

    return head1;
}

int main() {
    struct Node *head1 = malloc(sizeof(struct Node));
    struct Node *one = malloc(sizeof(struct Node));
    struct Node *two = malloc(sizeof(struct Node));
    struct Node *three = malloc(sizeof(struct Node));

    struct Node *head2 = malloc(sizeof(struct Node));
    struct Node *four = malloc(sizeof(struct Node));
    struct Node *five = malloc(sizeof(struct Node));
    struct Node *six = malloc(sizeof(struct Node));

    head1 = one;
    one->data = 1; head1->next = two;
    two->data = 2; two->next = three;
    three->data = 3; three->next = NULL;

    head2 = four;
    four->data = 4; head2->next = five;
    five->data = 5; five->next = six;
    six->data = 6; six->next = NULL;

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    struct Node *concatenatedHead = concatenateLists(head1, head2);
    printf("Concatenated List: ");
    printList(concatenatedHead);

    return 0;
}
