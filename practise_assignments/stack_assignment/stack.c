#include <stdio.h>
#define MAX 7
int top = -1;
int stack[MAX];

// Check whether stack is empty
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// Check whether stack is full
int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

//Push function
void push(){
	int value = 0;
	if(isFull()){
		printf("Stack Ovberflow!\n");
	}
	else{
		printf("Enter the value to push\n");
		scanf("%d",&value);
		top ++;
		stack[top] = value;
		printf("%d pushed into the stack\n", value);
	}
}

//Pop function
void pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow! Stack is empty.\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

// Display stack elements
void display()
{
    int i;

    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements (Top to Bottom):\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main(){
	int choice = 0;
	while(1){
		printf("Enter the choice\n");
		printf("1> Push an element\n");
		printf("2> Pop an element\n");
		printf("3> Display the elements\n");
		printf("4> Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: 
						push();
						break;
			case 2: 
						pop();
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
	}
		return 0;
}
