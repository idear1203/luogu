#include <stdio.h>

#define SIZE 1000005

int left[SIZE];
int right[SIZE];

int max = 1;

void getResult(int n);
void helper(int n, int rt, int depth);

void getResult(int n)
{
    helper(n, 1, 1);
}

void helper(int n, int rt, int depth)
{
    if (rt == 0 || rt > n)
    {
        return;
    }

    if (depth > max)
    {
        max = depth;
    }

    if (left[rt] == 0 && right[rt] == 0)
    {
        return;
    }

    helper(n, left[rt], depth + 1);
    helper(n, right[rt], depth + 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &left[i], &right[i]);
    }

    getResult(n);
    printf("%d\n", max);
    return 0;
}
