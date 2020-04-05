#include <stdio.h>

long long f[21][21][21] = { { {0} } };

long long getResult(long long a, long long b, long long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20)
    {
        return getResult(20, 20, 20);
    }
    else if (f[a][b][c] != 0)
    {
        return f[a][b][c];
    }
    else
    {
        long long result = 0;
        if (a < b && b < c)
        {
            result = getResult(a, b, c - 1) + getResult(a, b - 1, c - 1) - getResult(a, b - 1, c);
        }
        else
        {
            result = getResult(a - 1, b, c)
            + getResult(a - 1, b - 1, c)
            + getResult(a - 1, b, c - 1)
            - getResult(a - 1, b - 1, c - 1);
        }
        
        return f[a][b][c] = result;
    }
}

int main()
{
    long long a, b, c;
    while (scanf("%lld %lld %lld", &a, &b, &c) != 0)
    {
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }

        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, getResult(a, b, c));
    }

    return 0;
}
