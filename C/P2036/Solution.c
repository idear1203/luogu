#include <stdio.h>

#define SIZE 12
#define ABS(a) ((a) >= 0 ? (a) : -(a))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int getResult(int* s, int* b, int n);
int helper(int* s, int* b, int n, int cur, int totalS, int totalB);

int getResult(int* s, int* b, int n)
{
    if (n == 0)
    {
        return 0;
    }

    int min = helper(s, b, n, 0, s[0], b[0]);
    for (int i = 1; i < n; i++)
    {
        min = MIN(min, helper(s, b, n, i, s[i], b[i]));
    }

    return min;
}

int helper(int* s, int* b, int n, int cur, int totalS, int totalB)
{
    if (cur == n)
    {
        return ABS(totalS - totalB);
    }

    int min = ABS(totalS - totalB);
    for (int i = cur + 1; i < n; i++)
    {
        totalS *= s[i];
        totalB += b[i];
        min = MIN(min, helper(s, b, n, i, totalS, totalB));
        totalS /= s[i];
        totalB -= b[i];
    }

    return min;
}

int main()
{
    int n;
    scanf("%d", &n);
    int s[SIZE];
    int b[SIZE];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &s[i], &b[i]);
    }

    printf("%d\n", getResult(s, b, n));
    return 0;
}
