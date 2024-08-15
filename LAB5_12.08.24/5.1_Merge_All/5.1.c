#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r, int *comparison_count)
{
    int i = l, j = m + 1;
    int k = 0;
    int size = r - l + 1;

    int *temp = (int *)malloc(size * sizeof(int));
    if (!temp)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Merge the two halves into temp array
    while (i <= m && j <= r)
    {
        (*comparison_count)++;
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from left half
    while (i <= m)
    {
        (*comparison_count)++;
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right half
    while (j <= r)
    {
        (*comparison_count)++;
        temp[k++] = arr[j++];
    }

    // Copy the sorted elements back into the original array
    for (int p = 0; p < size; p++)
        arr[l + p] = temp[p];

    free(temp);
}

void merge_sort(int arr[], int l, int r, int *comparison_count)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m, comparison_count);
        merge_sort(arr, m + 1, r, comparison_count);
        merge(arr, l, m, r, comparison_count);
    }
}

int *read_file(const char *file_name, int *size)
{
    FILE *file = fopen(file_name, "r");
    if (!file)
    {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }

    fscanf(file, "%d", size);

    int *data = (int *)malloc(*size * sizeof(int));
    if (!data)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < *size; i++)
        fscanf(file, "%d", &data[i]);

    fclose(file);
    return data;
}

void write_file(const char *file_name, int data[], int size)
{
    FILE *file = fopen(file_name, "w");
    if (!file)
    {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }

    fprintf(file, "%d ", size);
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d ", data[i]);
    }

    fclose(file);
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void handle_sorting(const char *input_file, const char *output_file)
{
    int size;
    int *data = read_file(input_file, &size);

    printf("Before Sorting: ");
    print_array(data, size);

    int comparison_count = 0;
    clock_t start_time = clock();
    merge_sort(data, 0, size - 1, &comparison_count);
    clock_t end_time = clock();

    write_file(output_file, data, size);

    printf("After Sorting: ");
    print_array(data, size);
    printf("Number of Comparisons: %d\n", comparison_count);
    printf("Execution Time: %ld nanoseconds\n", (end_time - start_time) * 1000000000 / CLOCKS_PER_SEC);

    free(data);
}

int main()
{
    int opt;

    while (1)
    {
        printf("MAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");

        printf("Enter opt: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            handle_sorting("inAsce.dat", "outMergeAsce.dat");
            break;
        case 2:
            handle_sorting("inDesc.dat", "outMergeDesc.dat");
            break;
        case 3:
            handle_sorting("inRand.dat", "outMergeRand.dat");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid opt. Please try again.\n");
        }
    }

    return 0;
}
