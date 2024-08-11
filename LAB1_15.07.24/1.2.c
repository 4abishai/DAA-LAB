#include <stdio.h>

int sumArray(int arr[], int n)
{
    // Base case: if there's only one element, return it
    if (n <= 1)
    {
        return arr[0];
    }

    // Recursive case: add the last element to the sum of the rest
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = sumArray(arr, n);
    printf("Sum of array elements: %d\n", sum);

    return 0;
}