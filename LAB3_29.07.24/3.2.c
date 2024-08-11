#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fptr_write = fopen("writtenFile.txt", "w");
    if (!fptr_write)
        exit(0);

    int n = 5;
    int a[] = {10, 20, 33, 44, 55};

    // Write the data
    fprintf(fptr_write, "%d ", n);
    for (int i = 0; i < n; i++)
        fprintf(fptr_write, "%d ", a[i]);

    fclose(fptr_write);

    // Read from the written file
    FILE *fptr_read = fopen("writtenFile.txt", "r");
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
    fclose(fptr_read);
    return 0;
}
