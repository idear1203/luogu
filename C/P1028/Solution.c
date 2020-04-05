#include <stdio.h>

int getResult1(int n)
{
    int f[1002] = { 1, 1 };
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= i / 2; j++)
        {
            f[i] += f[j];
        }
    }

    return f[n];
}

int getResult(int n)
{
    int f[1002] = { 1, 1 };
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 2] + f[i / 2];
    }

    return f[n];
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", getResult(n));
}