#include <stdio.h>

// Insertion Sort implementation
void insertionSort(int arr[], int n) {
    // Start from the second element; treat arr[0] as the sorted portion
    for (int i = 1; i < n; i++) {
        
        // Store the current element as the "key" to be inserted
        int key = arr[i];
        int j = i - 1;

        // Move elements of the sorted portion that are greater than key
        // one position to the right, making room for the key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place the key in its correct position
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    insertionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}   