#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr[MAX];
int size = 0;

int getarray() {
    int i = 0;
    printf("Enter the size of the array\n");
    if (scanf("%d", &size) != 1) {
        printf("Invalid Input, try again!\n");
        exit(0);
    }
    if (size < 1 || size > MAX) {
        printf("Size must be between 1 and %d\n", MAX);
        exit(0);
    }
    printf("Enter the array elements\n");
    for (i = 0; i < size; i++) {
        printf("Enter element %d: ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid entry, integers only allowed!!\nExiting.....\n");
            exit(0);
        }
    }
    return size;
}

void mergesort(int left, int mid, int right) {
    int n1 = mid - left + 1;      
    int n2 = right - mid;
    int TA1[n1], TA2[n2];

    for (int i = 0; i < n1; i++)
        TA1[i] = arr[left + i];   
    for (int i = 0; i < n2; i++)
        TA2[i] = arr[mid + 1 + i]; 

    int i = 0, j = 0, k = left;   
    while (i < n1 && j < n2)
        arr[k++] = (TA1[i] <= TA2[j]) ? TA1[i++] : TA2[j++];  
    while (i < n1) arr[k++] = TA1[i++];  
    while (j < n2) arr[k++] = TA2[j++];  
}

void splitarray(int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    splitarray(left, mid);         
    splitarray(mid + 1, right);    
    mergesort(left, mid, right);
}

void display(int n) {
    for (int i = 0; i < n; i++)
        printf("%8d", arr[i]);
}

int main() {
    size = getarray();

    printf("Original array: ");
    display(size);
    printf("\n");

    splitarray(0, size - 1);

    printf("Sorted array: ");
    display(size);
    printf("\n");
    return 0;
}   