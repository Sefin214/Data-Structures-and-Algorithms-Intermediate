//Circular Queue using array
#include <stdio.h>
#define MAX 5
int front = -1, rear = -1;
int quarr[MAX];

// Check whether queue is empty
int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

// Check whether queue is full
int isFull()
{
    if (front == (rear+1)%MAX)
        return 1;
    else
        return 0;
}

//enqueue function
void enqueue(){
	int value = 0;
	if(isFull()){
		printf("Queue Overflow! Cannot push more elements\n");
        return;
	}

    //If it is the first element pushing
    if(front == -1 && rear == -1){
        front = 0;
    }

    printf("Enter the value to be enqueued\n");
    if(scanf("%d", &value) != 1){
    printf("Invalid input!\n");
    return;
    }
    rear = (rear+1)%MAX;
    quarr[rear] = value;
    printf("%d enqueued into the Queue\n", value);

}

//Dequeue function
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow! Queue is empty. Cannot dequeue anymore.\n");
        return;
    }
    
    printf("dequeued element: %d\n", quarr[front]);
    //If it is the last element 
    if(front == rear){
        front = rear = -1;
    }
    else
        front=(front+1)%MAX;
}

// Display queue elements
void display()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    else
    {
        printf("Queue elements (front to rear):\n\n");
		i = front;

		//printf function
        do
        {
            
            printf("%3d |", quarr[i]);
			if(i == rear)
				break;
			
			i = (i+1)%MAX;
            
        } while(1);
        printf("\n");
    }
}

int main(){
	int choice = 0;
	while(1){
        printf("\n==========================\n");
		printf("Enter the choice\n");
		printf("1> Enqueue an element\n");
		printf("2> Dequeue an element\n");
		printf("3> Display the elements\n");
		printf("4> Exit\n");
		if(scanf("%d", &choice) != 1){
        printf("Invalid input!\n");
        return 0;
        }
		switch(choice){
			case 1: 
						enqueue();
						break;
			case 2: 
						dequeue();
						break;
			case 3:
						display();
						break;
			case 4:
						printf("Exiting......\n");
						return 0;
			default:  
						printf("Wrong Choice\n");
						break;
		}

        printf("\n==========================\n");
	}
		return 0;
}
