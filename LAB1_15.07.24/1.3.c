//  Print sum of n nos using recursion
#include <stdio.h>

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + sum(n - 1);
    }
}

int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    printf("Sum of numbers from 1 to %d is: %d\n", n, sum(n));
    return 0;
}