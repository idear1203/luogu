#include <stdio.h>

#define SIZE (5000000 + 4)
int nums[SIZE];
void swap(int* nums, int i, int j);
int findKSmallest(int* nums, int n, int k);
int helper(int* nums, int n, int k, int start, int end);

int findKSmallest(int* nums, int n, int k) 
{
    if (nums == NULL)
    {
        return -1;
    }

    return helper(nums, n, k, 0, n - 1);
}

int helper(int* nums, int n, int k, int start, int end)
{
    if (start == end)
    {
        return nums[start];
    }

    int i = start;
    int j = end;
    int pivot = nums[start];
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
        swap(nums, start, i);
    }

    if (i == k)
    {
        return nums[k];
    }
    else if (i > k) 
    {
        return helper(nums, n, k, start, i - 1);
    }
    else
    {
        return helper(nums, n, k, i + 1, end);
    }
}

void swap(int* nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int main() 
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int result = findKSmallest(nums, n, k);
    printf("%d\n", result);
    return 0;
}
