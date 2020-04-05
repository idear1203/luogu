#include <stdio.h>

void getPermutation(int n);
void printNums(int* nums, int n);
int getNextPermutation(int* nums, int n);
void swap(int* nums, int i, int j);
void reverse(int* nums, int i, int j);

void getPermutation(int n)
{
    int nums[10];
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }

    do
    {
        printNums(nums, n);
    } while (getNextPermutation(nums, n));
}

void printNums(int* nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%5d", nums[i]);
    }

    printf("\n");
}

int getNextPermutation(int* nums, int n)
{
    int i;
    for (i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            break;
        }
    }

    if (i < 0)
    {
        return 0;
    }

    int j;
    for (j = n - 1; j > i; j--)
    {
        if (nums[j] > nums[i])
        {
            break;
        }
    }

    swap(nums, i, j);
    reverse(nums, i + 1, n - 1);
    return 1;
}

void swap(int* nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void reverse(int* nums, int i, int j)
{
    while (i < j)
    {
        swap(nums, i++, j--);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getPermutation(n);
    return 0;
}
