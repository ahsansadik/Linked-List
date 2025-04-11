#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        printf("%d popped from stack\n", value);
        return value;
    }
}

// Display the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function to test the stack
int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    return 0;
}
