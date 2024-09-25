//Stack Implementation in an Array


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Define a struct to represent the stack
typedef struct {
    int data[MAX_SIZE]; // array to store stack elements
    int top; // index of top element in stack
} Stack;

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = -1; // set top index to -1, indicating empty stack
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1; // return 1 if stack is empty, 0 otherwise
}

// Check if stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1; // return 1 if stack is full, 0 otherwise
}

// Push element onto stack
void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d.\n", element);
        return;
    }
    stack->data[++stack->top] = element; // increment top index and store element
}

// Pop element from stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->data[stack->top--]; // decrement top index and return popped element
}

// Peek at top element of stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return stack->data[stack->top]; // return top element without modifying stack
}

// Print stack elements
void printStack(Stack* stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printStack(&stack); // Output: Stack: 1 2 3

    printf("Popped: %d\n", pop(&stack)); // Output: Popped: 3
    printStack(&stack); // Output: Stack: 1 2

    printf("Peek: %d\n", peek(&stack)); // Output: Peek: 2

    return 0;
}