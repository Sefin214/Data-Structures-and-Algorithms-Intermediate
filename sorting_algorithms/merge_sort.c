
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int size = 0;

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

void mergesort(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int TA1[n1], TA2[n2];

    // Copy elements into temporary arrays
    for (int i = 0; i < n1; i++)
        TA1[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        TA2[i] = arr[mid + 1 + i];

    // Merge the two sorted arrays
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (TA1[i] <= TA2[j])
            arr[k++] = TA1[i++];
        else
            arr[k++] = TA2[j++];
    }

    // Copy remaining elements of TA1
    while (i < n1)
        arr[k++] = TA1[i++];

    // Copy remaining elements of TA2
    while (j < n2)
        arr[k++] = TA2[j++];
}

void splitarray(int left, int right)
{
    // Base condition
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Divide the array into two halves
    splitarray(left, mid);
    splitarray(mid + 1, right);

    // Merge the sorted halves
    mergesort(left, mid, right);
}

void display(int n)
{
    for (int i = 0; i < n; i++)
        printf("%8d", arr[i]);

    printf("\n");
}

int main()
{
    size = getarray();

    printf("\nOriginal array:\n");
    display(size);

    splitarray(0, size - 1);

    printf("\nSorted array:\n");
    display(size);

    return 0;
}
