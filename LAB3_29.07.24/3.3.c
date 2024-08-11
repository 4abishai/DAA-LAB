#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr_write = fopen("rand.txt", "w");
    if (!fptr_write)
        exit(0);

    int random = rand();

    // Write the data
    fprintf(fptr_write, "%d", random);
    fclose(fptr_write);

    // Read from the written file
    FILE *fptr_read = fopen("rand.txt", "r");
    if (!fptr_read)
        exit(0);

    int read_random;
    fscanf(fptr_read, "%d", &read_random);
    printf("%d", read_random);

    printf("\n");
    fclose(fptr_read);
    return 0;
}