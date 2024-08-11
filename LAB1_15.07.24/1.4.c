#include <stdio.h>

#define MAX_SIZE 100

void reverseArray(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArray(arr, start + 1, end - 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE)
    {
        printf("Invalid array size. Please enter a size between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, size);

    reverseArray(arr, 0, size - 1);

    printf("Reversed array: ");
    printArray(arr, size);

    return 0;
}