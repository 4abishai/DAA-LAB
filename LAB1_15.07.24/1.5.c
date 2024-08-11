// Add digits of a no using recursion
#include <stdio.h>

int sumOfDigits(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return (n % 10) + sumOfDigits(n / 10);
    }
}

int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    int result = sumOfDigits(num);
    printf("Sum of digits of %d is: %d\n", num, result);

    return 0;
}