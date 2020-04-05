#include <stdio.h>

int getResult(int n)
{
    int f[20] = { 1, 1 };
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            f[i] += f[j] * f[i - 1 -j];
        }
    }

    return f[n];
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", getResult(n));
}
