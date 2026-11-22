
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

    // If queue is empty
    if (front == NULL)
    {
        front = rear = newnode;
        newnode->next = front;
    }
    else
    {
        newnode->next = front;
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d inserted into the circular queue.\n", value);
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

    printf("%d removed from the circular queue.\n",
           front->data);

    // If only one node exists
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
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

    printf("\nCircular Queue (Front to Rear):\n");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;

    } while (temp != front);

    printf("(Back to Front)\n");
}

// Free all nodes
void freeQueue()
{
    struct node *temp;

    if (front == NULL)
        return;

    rear->next = NULL;

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
        printf("\n===== CIRCULAR QUEUE MENU =====\n");
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
