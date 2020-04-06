#include <stdio.h>

#define SIZE 1000005

int nums[SIZE];

int getResult(int n, int target)
{
    int start = 0;
    int end = n;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start < n && nums[start] == target ? start + 1 : -1;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int num;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num);
        if (i == 0)
        {
            printf("%d", getResult(n, num));
        }
        else if (i < m - 1)
        {
            printf(" %d", getResult(n, num));
        }
        else
        {

            printf(" %d\n", getResult(n, num));
        }
    }

    return 0;
}
