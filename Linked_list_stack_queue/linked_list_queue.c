
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

// Front and rear pointers
struct node *front = NULL;
struct node *rear = NULL;

// Enqueue operation
void enqueue()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("\nQueue Overflow! Memory allocation failed.\n");
        return;
    }

    printf("Enter the value to insert: ");

    if (scanf("%d", &value) != 1)
    {
        printf("Invalid input!\n");
        free(newnode);
        return;
    }

    newnode->data = value;
    newnode->next = NULL;

    // If queue is empty
    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d inserted into the queue.\n", value);
}

// Dequeue operation
void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }

    temp = front;

    printf("%d removed from the queue.\n", front->data);

    front = front->next;

    // If the last node was removed
    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
}

// Peek operation
void peek()
{
    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nFront element: %d\n", front->data);
}

// Display operation
void display()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    temp = front;

    printf("\nQueue elements (Front to Rear):\n");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Free all remaining nodes
void freeQueue()
{
    struct node *temp;

    while (front != NULL)
    {
        temp = front;
        front = front->next;
        free(temp);
    }

    rear = NULL;
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
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
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                freeQueue();
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    freeQueue();

    return 0;
}
