#include <stdio.h>

// Bubble Sort implementation
void bubbleSort(int arr[], int n) {
    int t = 0;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
              t=arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = t;  
            }
        }
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}   