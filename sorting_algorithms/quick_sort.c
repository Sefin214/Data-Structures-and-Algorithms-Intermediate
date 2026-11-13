#include <stdio.h>
#define MAX 100

int arr[MAX];
int size = 0;

//array creation function
int getarray(){
    int i = 0;
    printf("Enter the size of the array\n");
    
    //getting size
    if(scanf("%d",&size)!=1){
        printf("Invalid Input, try again!\n");
        exit();
    }

    printf("Enter the array elements \n");
    for(i=0;i<size;i++){
        printf("Enter element %d : ",i);
        if(scanf("%d",&arr[i])!=1){
            printf("Invalid entry, integers only allowed!!\nExiting.....\n");
            exit();
        }
    }
    return size;
}

//splitting function
void splitarray(){

}


//merge sort function
void quicksort(int size){

}

//display function
void display(int size){
    int i = 0;
    for(i=0;i<size;i++){
        printf("%8d|",arr[i]);
    }
}



//main function
int main() {
    int size = 0;
    
    size = getarray();

    printf("Original array: ");
    display(size);
    printf("\n");

    quicksort(size);

    printf("Sorted array: ");
    display(size);
    printf("\n");

    return 0;
}   