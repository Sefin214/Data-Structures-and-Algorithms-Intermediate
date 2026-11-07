//Linear search through array using for loop
//Complexity is O(n)
#include <stdio.h>

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int size = 7, key = 0, i = 0, f = 0;

    printf("Enter the key to search for : ");
    if(scanf("%d", &key)!=1){
        printf("Invalid Input, only supports integer values!\n");
        return 0;
    }

    //Linear search
    for(i=0;i<size;i++){
        if(arr[i] == key){
            f = 1;
            break;
        }
    }

    //checks if found or not
    if(1 == f)
        printf("Value found at position %d\n",i);
    else
        printf("Value not found in the array\n");
    return 0;
}