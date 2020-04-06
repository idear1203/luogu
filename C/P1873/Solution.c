#include <stdio.h>

#define SIZE 1000005
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int nums[SIZE];

int check(int n, int m, int h);

int getResult(int n, int m)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        max = MAX(nums[i], max);
    }

    int start = 0;
    int end = max;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (check(n, m, mid))
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start - 1;
}

int check(int n, int m, int h)
{
    long long ans = 0;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (nums[i] - MIN(nums[i], h));
        if (ans >= m)
        {
            ret = 1;
            break;
        }
    }

    return ret;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", getResult(n, m));
    return 0;
}
