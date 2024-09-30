#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize the stack (top pointer)
struct Node* top = NULL;

// Function to initialize the stack
void initializeStack() {
    top = NULL;
}

// Function to push an element onto the stack
void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return data;
}

// Function to peek at the top element of the stack
int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Main function to test the stack operations
int main() {
    initializeStack();

    push(10);
    push(20);
    push(30);

    printf("Top element is %d\n", peek());

    printf("Popped element is %d\n", pop());
    printf("Popped element is %d\n", pop());

    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}