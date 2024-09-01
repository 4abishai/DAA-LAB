#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

long long comparisons = 0;

void insertion_sort(int A[], int n)
{
    for (int j = 1; j < n; j++)
    {
        int key = A[j];
        int i = j - 1;

        while (i > 0 && A[i] > key)
        {
            ++comparisons;
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
        ++comparisons;
    }
}

void compare(int inputs[], int steps[], int step_size)
{
    for (int s = 0; s < step_size; s++)
    {
        int input_size = steps[s];
        int *temp = (int *)malloc(input_size * sizeof(int));
        for (int i = 0; i < input_size; i++)
            temp[i] = inputs[i];
        comparisons = 0;
        insertion_sort(temp, input_size);
        printf("%d elements: %lld\n", input_size, comparisons);
    }
}

int main()
{

    // Read contents of file into array
    FILE *fptr = fopen("unsorted.txt", "r");
    int inputs[MAX];
    int n = 0;
    while (fscanf(fptr, "%d", &inputs[n]) == 1 && n < MAX)
        n++;
    fclose(fptr);

    // Get steps
    int steps_size = 0;
    printf("Enter number of steps: ");
    scanf("%d", &steps_size);
    int steps[steps_size];
    printf("Enter inputs for each step: ");
    for (int i = 0; i < steps_size; i++)
        scanf("%d", &steps[i]);

    // Compare Unsorted Arr (Average Case)
    printf("Comparisons for unsorted array (average case): \n");
    compare(inputs, steps, steps_size);

    // Sort the array
    insertion_sort(inputs, n);

    // Compare Sorted Arr (Best Case)
    printf("Comparisons for sorted array: \n");
    compare(inputs, steps, steps_size);

    return 0;
}