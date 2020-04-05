#include <stdio.h>

#define SIZE 1002

void swap(long long* nums, int i, int j);
void swapInt(int* nums, int i, int j);
void getResult(long long* nums, int n);

int order[SIZE];
void getResult(long long* nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        order[i] = i + 1;
    }

    int flag = 1;
    for (int i = 0; i < n - 1 && flag; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                flag = 1;
                swap(nums, j, j + 1);
                swapInt(order, j, j + 1);
            }
        }
    }
}

void swap(long long* nums, int i, int j)
{
    long long tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void swapInt(int* nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int main()
{
    int n;
    long long nums[SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &nums[i]);
    }

    getResult(nums, n);
    long long total = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", order[i]);
        total += (n - 1 - i) * nums[i];
    }

    if (n > 0)
    {
        printf("%d\n", order[n - 1]);
        printf("%.2lf\n", total / (double)n);
    }

    return 0;
}
