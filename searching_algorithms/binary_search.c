//Binary search algorithm
//time complexity O(log(n))
//Works only on sorted arrays
#include <stdio.h>

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int key = 0, mid = 0, f = 0, size = 8, low = 0, high = (size-1);

    printf("Enter the key to be searched : ");
    
    //error checking for input
    if(scanf("%d", &key)!=1){
        printf("Invalid input, integer only supported!\n");
        return 0;
    }

    //binary search condition
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid] == key){
            printf("Key found at position %d\n",mid);
            f = 1;
            break;
        }
        else if(key>mid){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    if(0 == f){
        printf("Element not found! \n");
    }
    return 0;
}