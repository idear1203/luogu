#include <stdio.h>

#define SIZE 1300
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int getResult(int* nums, int n)
{
    int dp[SIZE] = {0};
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = sum / 2; j >= nums[i]; j--)
        {
            dp[j] = MAX(dp[j], nums[i] + dp[j - nums[i]]);
        }
    }

    return sum - dp[sum / 2];
}

int main()
{
    int n[4];
    int nums[22];
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &n[i]);
    }

    int total = 0;
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < n[j]; i++)
        {
            scanf("%d", &nums[i]);
        }

        total += getResult(nums, n[j]);
    }

    printf("%d\n", total);
    return 0;
}
