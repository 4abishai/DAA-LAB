// Print n nos using recursion
#include <stdio.h>

void printNumbers(int n)
{
    if (n > 0)
    {
        printNumbers(n - 1);
        printf("%d ", n);
    }
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Numbers from 1 to %d are: ", n);
    printNumbers(n);

    return 0;
}