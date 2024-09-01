#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

long long comparisons = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int r)
{
    int pivot = A[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; j++)
    {
        ++comparisons;
        if (A[j] <= pivot)
        {
            // Bring the smaller element to the side of i
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);

    return (i + 1);
}

void quick_sort(int A[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(A, l, r);
        quick_sort(A, l, pi - 1);
        quick_sort(A, pi + 1, r);
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
        quick_sort(temp, 0, input_size - 1);
        printf("%d elements: %lld\n", input_size, comparisons);
        free(temp);
    }
}

int main()
{
    // Open text file
    FILE *fptr = fopen("unsorted.txt", "r");

    // Read inputs into array
    int inputs[MAX];
    int n = 0;
    while (fscanf(fptr, "%d", &inputs[n]) == 1 && n < MAX)
        n++;
    fclose(fptr);

    // Get the steps
    int steps_size = 0;
    printf("Enter number of steps: ");
    scanf("%d", &steps_size);
    int steps[steps_size];
    printf("Enter inputs for each step: ");
    for (int i = 0; i < steps_size; i++)
        scanf("%d", &steps[i]);

    // Compare average case
    printf("Average Case Comparisons: \n");
    compare(inputs, steps, steps_size);

    // Sort the array
    quick_sort(inputs, 0, n - 1);

    // Compare worst case
    printf("Worst Case Comparisons: \n");
    compare(inputs, steps, steps_size);

    return 0;
}