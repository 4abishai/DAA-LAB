#include <stdio.h>

void EXCHANGE(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2)
{
    if (p2 <= 1)
        return;

    // Shift elements to the right
    for (int i = p2 - 1; i > 0; i--)
        EXCHANGE(p1 + i, p1 + i - 1);
}

int main()
{
    int N = 9;
    int A[N];

    printf("Enter an array A of size N (9):");
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    int x;
    printf("\nROTATE_RIGHT(A, x)\n\nEnter x: ");
    scanf("%d", &x);

    printf("Before ROTATE: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    ROTATE_RIGHT(A, x);

    printf("After ROTATE: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}