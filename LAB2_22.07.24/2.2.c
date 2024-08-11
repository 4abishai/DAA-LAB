#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n], prefix_sum[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    prefix_sum[0] = a[0];

    for (int i = 1; i < n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + a[i];

    printf("Prefix Sum Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", prefix_sum[i]);
    printf("\n");

    return 0;
}
