#include <stdio.h>

#define SIZE 100002
#define MIN(a, b) ((a) < (b) ? (a) : (b))

long long getResult(int* nums, int n, int x)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return nums[0] > x ? nums[0] - x : 0;
    }

    // from left
    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        int sum = nums[i] + nums[i - 1];
        if (sum > x)
        {
            int count = MIN(sum - x, nums[i]);
            nums[i] -= count;
            ans += count;
        }
    }

    // from right
    for (int i = n - 2; i >= 0; i--)
    {
        int sum = nums[i] + nums[i + 1];
        if (sum > x)
        {
            int count = MIN(sum - x, nums[i]);
            nums[i] -= count;
            ans += count;
        }
    }

    return ans;
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int nums[SIZE];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("%lld\n", getResult(nums, n, x));
}
