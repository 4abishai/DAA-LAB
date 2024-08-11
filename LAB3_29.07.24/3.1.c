#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fptr = fopen("file.txt", "r");
    if (!fptr)
        exit(0);

    int n;
    fscanf(fptr, "%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        fscanf(fptr, "%d", &arr[i]);

    printf("Data read from the file: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    fclose(fptr);
    return 0;
}
