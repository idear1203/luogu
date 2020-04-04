#include <stdio.h>

#define SIZE (100000 + 4)
void qsort(int* nums, int start, int end);
void swap(int* nums, int i, int j);

void qsort(int* nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = nums[start];
    int i = start;
    int j = end;
    while (i < j)
    {
        while (i < j && nums[j] >= pivot)
        {
            j--;
        }

        while (i < j && nums[i] <= pivot)
        {
            i++;
        }

        if (i < j)
        {
            swap(nums, i, j);
        }
    }

    if (i > start)
    {
        swap(nums, i, start);
    }

    qsort(nums, start, i -1);
    qsort(nums, i + 1, end);
}

void swap(int* nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int nums[SIZE];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    qsort(nums, 0, n - 1);
    if (n > 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            printf("%d ", nums[i]);
        }

        printf("%d\n", nums[n - 1]);
    }
}