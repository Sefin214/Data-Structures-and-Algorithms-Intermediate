
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

// Top pointer
struct node *top = NULL;

// Push operation
void push()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("\nStack Overflow! Memory allocation failed.\n");
        return;
    }

    printf("Enter the value to push: ");
    if (scanf("%d", &value) != 1)
    {
        printf("Invalid input!\n");
        free(newnode);
        return;
    }

    newnode->data = value;
    newnode->next = top;

    top = newnode;

    printf("%d pushed into the stack.\n", value);
}

// Pop operation
void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("\nStack Underflow! Stack is empty.\n");
        return;
    }

    temp = top;

    printf("%d popped from the stack.\n", top->data);

    top = top->next;

    free(temp);
}

// Peek operation
void peek()
{
    if (top == NULL)
    {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nTop element: %d\n", top->data);
}

// Display operation
void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("\nStack is empty.\n");
        return;
    }

    temp = top;

    printf("\nStack elements (Top to Bottom):\n");

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Free all remaining nodes
void freeStack()
{
    struct node *temp;

    while (top != NULL)
    {
        temp = top;
        top = top->next;
        free(temp);
    }
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            break;
        }

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                freeStack();
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    freeStack();
    return 0;
}
