#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int lcs(char *X, char *Y, char *sub)
{
    int m = strlen(X);
    int n = strlen(Y);
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int len = L[m][n];
    sub[len] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            sub[len - 1] = X[i - 1];
            i--, j--, len--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return L[m][n];
}

int main()
{
    char X[100], Y[100], sub[100];

    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the second string: ");
    scanf("%s", Y);

    printf("Length of LCS is %d\n", lcs(X, Y, sub));
    printf("LCS: %s\n", sub);

    return 0;
}
