#include <stdio.h>
#define MAX 5   


void push(int stack[], int *top, int maxSize);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main() {
    int stack[MAX];
    int top = -1;  
    int choice;

    do {
        printf("\n=== STACK OPERATIONS MENU ===\n");
        printf("1. PUSH (Insert Element)\n");
        printf("2. POP (Remove Element)\n");
        printf("3. PEEK (View Top Element)\n");
        printf("4. DISPLAY (Show All Elements)\n");
        printf("0. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, &top, MAX);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}


void push(int stack[], int *top, int maxSize) {
    int value;

    if (*top == maxSize - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        (*top)++;
        stack[*top] = value;
        printf("%d pushed into the stack.\n", value);
    }
}


void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow! No element to pop.\n");
    } else {
        printf("Popped element: %d\n", stack[*top]);
        (*top)--;
    }
}


void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}


void display(int stack[], int top) {
	int i;
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

