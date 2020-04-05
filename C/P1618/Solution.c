#include <stdio.h>

#define EP (0.00000001)
#define ABS(a) ((a) > 0 ? (a) : -(a))

int getNextPermutation(int* nums);
void swap(int* nums, int i, int j);
void reverse(int* nums, int i, int j);
int getNum(int* nums, int i, int j);

int getResult(int a, int b, int c)
{
    int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int hasResult = 0;
    do
    {
        int x = getNum(nums, 0, 2);
        int y = getNum(nums, 3, 5);
        int z = getNum(nums, 6, 8);
        double xa = ((double) x) / a;
        double yb = ((double) y) / b;
        double zc = ((double) z) / c;
        if (ABS(xa - yb) < EP && ABS(xa - zc) < EP && ABS(yb - zc) < EP)
        {
            printf("%d %d %d\n", x, y, z);
            hasResult = 1;
        }

    } while (getNextPermutation(nums));

    return hasResult;
}

int getNum(int* nums, int i, int j)
{
    int num = 0;
    while (i <= j)
    {
        num = num * 10 + nums[i++];
    }

    return num;
}

int getNextPermutation(int* nums)
{
    // Find the first number in natural order from right
    int i;
    for (i = 7; i >= 0; i--)
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

    // Find the first number that is larger than nums[i]
    int j;
    for (j = 8; j > i; j--)
    {
        if (nums[j] > nums[i])
        {
            break;
        }
    }

    swap(nums, i, j);
    reverse(nums, i + 1, 8);
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
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int hasResult = 0;
    if (a != 0 && b != 0 && c != 0)
    {
        hasResult = getResult(a, b, c);
    }

    if (!hasResult)
    {
        printf("No!!!\n");
    }

    return 0;
}
