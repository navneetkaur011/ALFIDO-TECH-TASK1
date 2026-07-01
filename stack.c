#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 5 // Defining a fixed maximum capacity for the stack

// Structure to represent Stack
struct Stack {
    int top;
    int arr[MAX_CAPACITY];
};

// Function to initialize stack
void initialize(struct Stack* stack) {
    stack->top = -1; // -1 indicates stack is empty 
}

// Checking if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_CAPACITY - 1;
}

// Checking if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Insert Operation
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
    printf("Successfully pushed %d onto the stack.\n", value);
}

// Delete Operation
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1; // Returning -1 to indicate error/empty
    }
    int poppedValue = stack->arr[stack->top];
    stack->top--;
    return poppedValue;
}

// Search Operation
int search(struct Stack* stack, int target) {
    if (isEmpty(stack)) {
        return -1;
    }
    // Traverse from the top element down to 0
    for (int i = stack->top; i >= 0; i--) {
        if (stack->arr[i] == target) {
            return stack->top - i; // Returns the distance from the top
        }
    }
    return -1;// Element not found
}

// Function to display the current state of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current Stack (Top -> Bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("[%d] ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack myStack;
    initialize(&myStack);
    
    int choice, val, searchResult;

    printf("   ALFIDO TECH STACK INTERACTIVE SYSTEM      \n");

    while (1) {
        printf("\n--- Available Operations ---\n");
        printf("1. Push (Insert Element)\n");
        printf("2. Pop (Delete Element)\n");
        printf("3. Search for an Element\n");
        printf("4. Display Stack Current Layout\n");
        printf("5. Exit Program\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid text entry. Exiting program gracefully.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push onto stack: ");
                scanf("%d", &val);
                push(&myStack, val);
                break;
                
            case 2:
                val = pop(&myStack);
                if (val != -1) {
                    printf("Successfully popped element: %d\n", val);
                }
                break;
                
            case 3:
                printf("Enter element value to look for: ");
                scanf("%d", &val);
                searchResult = search(&myStack, val);
                if (searchResult != -1) {
                    printf("Success: Element %d found at depth index %d from top.\n", val, searchResult);
                } else {
                    printf("Result: Element %d was not found in the stack.\n", val);
                }
                break;
                
            case 4:
                display(&myStack);
                break;
                
            case 5:
                printf("Exiting application. Thanks, Bye Bye!\n");
                return 0;
                
            default:
                printf("Invalid selection option! Please choose between 1 and 5.\n");
        }
    }
    return 0;
}