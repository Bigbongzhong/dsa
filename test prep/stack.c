#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* data;      // Pointer for dynamic array
    int top;        // Index of the top element
    int capacity;   // Current capacity of the stack
} Stack;

void initStack(Stack* stack, int initialCapacity) {
    stack->data = (int*)malloc(initialCapacity * sizeof(int));
    if (!stack->data) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = -1;
    stack->capacity = initialCapacity;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void resizeStack(Stack* stack) {
    int newCapacity = stack->capacity * 2; // Double the capacity
    stack->data = (int*)realloc(stack->data, newCapacity * sizeof(int));
    if (!stack->data) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
    stack->capacity = newCapacity;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full, resizing...\n");
        resizeStack(stack);
    }
    stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Return an error value
    }
    return stack->data[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return an error value
    }
    return stack->data[stack->top];
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

void freeStack(Stack* stack) {
    free(stack->data); // Free dynamically allocated memory
}

int main() {
    Stack stack;
    int initialCapacity = 5; // Start with a small capacity
    initStack(&stack, initialCapacity);

    int choice, value;

    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    freeStack(&stack); // Free allocated memory before exiting
    return 0;
}