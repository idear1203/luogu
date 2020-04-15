#include <stdio.h>

#define SIZE 102

void getResult(int* nums, int n, int m)
{
    // Note for linked list, we use previous node here
    // so that we can remove the next node.
    int prev = n - 1;
    while (nums[prev] != prev)
    {
        // count m - 1 times
        for (int i = 0; i < m - 1; i++)
        {
            prev = nums[prev];
        }

        int selected = nums[prev];
        printf("%d ", selected + 1);
        nums[prev] = nums[selected];
        nums[selected] = -1;
    }

    printf("%d\n", prev + 1);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int nums[SIZE];
    for (int i = 0; i < n; i++)
    {
        nums[i] = (i + 1) % n;
    }

    getResult(nums, n, m);
    return 0;
}
