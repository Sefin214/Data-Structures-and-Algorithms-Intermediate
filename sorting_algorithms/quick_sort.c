
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int size = 0;

// Array creation function
int getarray()
{
    int i = 0;

    printf("Enter the size of the array: ");

    if (scanf("%d", &size) != 1)
    {
        printf("Invalid input, try again!\n");
        exit(0);
    }

    if (size < 1 || size > MAX)
    {
        printf("Size must be between 1 and %d\n", MAX);
        exit(0);
    }

    printf("Enter the array elements:\n");

    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i);

        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid entry, integers only allowed!\n");
            exit(0);
        }
    }

    return size;
}

// Splitting function
int splitarray(int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct position
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort function
void quicksort(int low, int high)
{
    if (low < high)
    {
        int pivotindex = splitarray(low, high);

        // Sort elements before the pivot
        quicksort(low, pivotindex - 1);

        // Sort elements after the pivot
        quicksort(pivotindex + 1, high);
    }
}

// Display function
void display(int size)
{
    int i = 0;

    for (i = 0; i < size; i++)
    {
        printf("%8d|", arr[i]);
    }
}

// Main function
int main()
{
    size = getarray();

    printf("\nOriginal array: ");
    display(size);
    printf("\n");

    quicksort(0, size - 1);

    printf("Sorted array: ");
    display(size);
    printf("\n");

    return 0;
}
