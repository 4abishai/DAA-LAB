#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr_write = fopen("randRange.txt", "w");
    if (!fptr_write)
        exit(0);

    int low_bnd, up_bnd, no_of_int;
    printf("Enter lower bound, upper bound, number of integers: ");
    scanf("%d %d %d", &low_bnd, &up_bnd, &no_of_int);

    fprintf(fptr_write, "%d ", no_of_int);
    for (int i = 0; i < no_of_int; i++)
    {
        int random = rand() % (up_bnd - low_bnd + 1) + low_bnd;
        fprintf(fptr_write, "%d ", random);
    }

    fclose(fptr_write);

    // Read from the written file
    FILE *fptr_read = fopen("randRange.txt", "r");
    if (!fptr_read)
        exit(0);

    int m;
    fscanf(fptr_read, "%d", &m);

    int b[m];
    for (int i = 0; i < m; i++)
        fscanf(fptr_read, "%d", &b[i]);

    printf("Data written into file: ");
    for (int i = 0; i < m; i++)
        printf("%d ", b[i]);

    printf("\n");
    return 0;
}