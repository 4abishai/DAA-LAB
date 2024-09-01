#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

long long comparisons = 0;

void merge(int A[], int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0;
    int *temp = (int *)malloc((r - l + 1) * sizeof(int));

    while (i <= mid && j <= r)
    {
        comparisons++;
        temp[k++] = A[i] < A[j] ? A[i++] : A[j++];
    }

    while (i <= mid)
        temp[k++] = A[i++];

    while (j <= r)
        temp[k++] = A[j++];

    for (int p = 0; p < k; p++)
        A[p + l] = temp[p];

    free(temp);
}

void merge_sort(int A[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(A, l, mid);
        merge_sort(A, mid + 1, r);
        merge(A, l, mid, r);
    }
}

void compare(int inputs[], int steps[], int steps_size)
{
    for (int s = 0; s < steps_size; s++)
    {
        int input_size = steps[s];

        int *temp = (int *)malloc(input_size * sizeof(int));
        for (int i = 0; i < input_size; i++)
            temp[i] = inputs[i];

        comparisons = 0;
        merge_sort(temp, 0, input_size - 1);
        printf("%d elements: %lld\n", input_size, comparisons);

        free(temp);
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
    merge_sort(inputs, 0, n - 1);

    // Compare Sorted Arr
    printf("Comparisons for sorted array: \n");
    compare(inputs, steps, steps_size);

    return 0;
}