#include <stdio.h>

#define SIZE (2000000 + 10)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int aux[SIZE];
int nums[SIZE];

void radix_sort(int* nums, int m)
{
    int radix = 1;
    int d = 10;
    int max = 0;
    for (int i = 0; i < m; i++) 
    {
        max = MAX(max, nums[i]);
    }

    while (max / radix > 0)
    {
        int count[10] = {0};
        for (int i = 0; i < m; i++)
        {
            count[(nums[i] / radix) % d]++;
        }

        for (int i = 1; i < d; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = m - 1; i >= 0; i--)
        {
            int idx = count[(nums[i] / radix) % 10];
            aux[--count[(nums[i] / radix) % 10]] = nums[i];
        }

        for (int i = 0; i < m; i++)
        {
            nums[i] = aux[i];
        }

        radix *= d;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &nums[i]);
    }

    radix_sort(nums, m);
    if (m > 0)
    {
        for (int i = 0; i < m - 1; i++)
        {
            printf("%d ", nums[i]);
        }

        printf("%d\n", nums[m - 1]);
    }

    return 0;
}