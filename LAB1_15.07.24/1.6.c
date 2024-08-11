// Reverse a given no using recursion
#include <stdio.h>

int reverseNumber(int n, int reversed)
{
    if (n == 0)
    {
        return reversed;
    }
    else
    {
        return reverseNumber(n / 10, reversed * 10 + n % 10);
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

    int reversed = reverseNumber(num, 0);
    printf("Reversed number: %d\n", reversed);

    return 0;
}