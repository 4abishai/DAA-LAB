#include <stdio.h>
#include <stdlib.h>

int getGcd(int a, int b)
{
    if (b == 0)
        return a;

    return getGcd(b, a % b);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: <input_file> <output_file>\n");
        return 1;
    }

    char *inFile = argv[1];
    char *outFile = argv[2];

    FILE *inPtr = fopen(inFile, "r");
    FILE *outPtr = fopen(outFile, "w");

    if (inPtr == NULL || outPtr == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }

    int size;
    fscanf(inPtr, "%d", &size);

    if (size < 2)
    {
        printf("Not enough numbers for GCD calculation.\n");
        fclose(inPtr);
        fclose(outPtr);
        return 1;
    }

    int A[size];

    for (int i = 0; i < size; i++)
    {
        fscanf(inPtr, "%d", &A[i]);
        printf("%d ", A[i]);
    }

    printf("\n");

    for (int i = 0; i + 1 < size; i += 2)
    {
        fprintf(outPtr, "%d ", getGcd(A[i], A[i + 1]));
        printf("%d %d\n", A[i], A[i + 1]);
    }

    fclose(inPtr);
    fclose(outPtr);

    return 0;
}
