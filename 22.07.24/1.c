#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int smallest = INT_MAX;
    int second_smallest = INT_MAX;
    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < smallest)
        {
            second_smallest = smallest;
            smallest = a[i];
        }
        // If only smaller than second smallest
        else if (a[i] < second_smallest && a[i] != smallest)
            second_smallest = a[i];

        if (a[i] > largest)
        {
            second_largest = largest;
            largest = a[i];
        }
        // If only larger than second largest
        else if (a[i] > second_largest && a[i] != largest)
            second_largest = a[i];
    }

    printf("Second smallest, Second largest: %d %d\n", second_smallest, second_largest);

    return 0;
}