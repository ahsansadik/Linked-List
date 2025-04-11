#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Enqueue (insert) an element
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

// Dequeue (remove) an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    } else {
        int value = queue[front];
        front++;
        printf("%d dequeued from queue\n", value);
        return value;
    }
}

// Display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function to test the queue
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    return 0;
}
