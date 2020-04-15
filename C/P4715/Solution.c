#include <stdio.h>

#define SIZE (150)

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int getResult(int* nums, int n)
{
    int leftMax = nums[0];
    int left = 1;
    for (int i = 1; i < n / 2; i++)
    {
        if (nums[i] > leftMax)
        {
            left = i + 1;
            leftMax = nums[i];
        }
    }

    int rightMax = nums[n / 2];
    int right = n / 2 + 1;
    for (int i = n / 2 + 1; i < n ; i++)
    {
        if (nums[i] > rightMax)
        {
            right = i + 1;
            rightMax = nums[i];
        }
    }

    return leftMax > rightMax ? right : left;
}

int main()
{
    int n;
    scanf("%d", &n);
    int nums[SIZE];
    n = 1 << n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", getResult(nums, n));
    return 0;
}