#include <stdio.h>

void helper(int* nums, int n, int r, int curIdx, int start);
void printNums(int* nums, int r);

void getCombination(int n, int r)
{
    int nums[21] = {0};
    helper(nums, n, r, 0, 1);
}

void helper(int* nums, int n, int r, int curIdx, int start)
{
    if (curIdx == r)
    {
        printNums(nums, r);
    }

    for (int num = start; num <= n; num++)
    {
        nums[curIdx] = num;
        helper(nums, n, r, curIdx + 1, num + 1);
    }
}

void printNums(int* nums, int r)
{
    for (int i = 0; i < r; i++)
    {
        printf("%3d", nums[i]);
    }

    printf("\n");
}

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    getCombination(n, r);
    return 0;
}
