#include <stdio.h>

#define SIZE 10005
#define MAX(a, b) ((a) > (b) ? (a) : (b))
void radixSort(int* nums, int n);
int getResult1(int* nums, int n);
int getResult(int* nums, int n);

int heapSize = 0;

int getResult(int* nums, int n)
{
    create(nums, n);
    int ans = 0;
    while (heapSize > 1)
    {
        int x = pop(nums);
        int y = pop(nums);
        push(nums, x + y);
        ans += x + y;
    }

    return ans;
}

void create(int* nums, int n)
{
    heapSize = n;
    for (int i = parent(n - 1); i >= 0; i--)
    {
        update(nums, i);
    }
}

void update(int* nums, int rt)
{
    int min = rt;
    int l = left(rt);
    int r = right(rt);
    if (l < heapSize && nums[l] < nums[min])
    {
        min = l;
    }

    if (r < heapSize && nums[r] < nums[min])
    {
        min = r;
    }

    if (min != rt)
    {
        swap(nums, rt, min);
        update(nums, min);
    }
}

int pop(int* nums)
{
    int ans = 0;
    if (heapSize > 0)
    {
        ans = nums[0];
        nums[0] = nums[--heapSize];
        update(nums, 0);
    }

    return ans;
}

void push(int* nums, int value)
{
    nums[heapSize++] = value;
    int i = heapSize - 1;
    while (i > 0 && nums[i] < nums[parent(i)])
    {
        swap(i, parent(i));
        i = parent(i);
    }
}

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

int root(int i)
{
    return (i - 1) >> 2;
}

int getResult1(int* nums, int n)
{
    if (n <= 1)
    {
        return 0;
    }

    radixSort(nums, n);

    int startIdx = 0;
    int endIdx = n - 1;
    int count = 0;
    int flag = 1;
    while (startIdx < endIdx)
    {
        nums[startIdx + 1] = nums[startIdx] + nums[startIdx + 1];
        count += nums[startIdx + 1];
        startIdx = startIdx + 1;
        int pivot = nums[startIdx];
        int i = startIdx + 1;
        while (i <= endIdx && nums[i] < pivot)
        {
            nums[i - 1] = nums[i];
            i++;
        }
        nums[i - 1] = pivot;
    }

    return count;
}

void radixSort(int* nums, int n)
{
    int d = 10;
    int aux[SIZE];
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        max = MAX(max, nums[i]);
    }

    int radix = 1;
    while (max / radix > 0)
    {
        int count[10] = {0};
        for (int i = 0; i < n; i++)
        {
            count[nums[i] / radix % d]++;
        }

        for (int i = 1; i < d; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            aux[--count[nums[i] / radix % 10]] = nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] = aux[i];
        }

        radix *= d;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int nums[SIZE];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", getResult(nums, n));
    return 0;
}
#define MAX(a, b) ((a) > (b) ? (a) : (b))
void radixSort(int* nums, int n);
int getResult1(int* nums, int n);
int getResult(int* nums, int n);
void swap(int* nums, int i, int j);

int heapSize = 0;
void create(int* nums, int n);
void update(int* nums, int rt);
int pop(int* nums);
void push(int* nums, int value);
int left(int i);
int right(int i);
int parent(int i);
void print(int* nums, int n);

int getResult(int* nums, int n)
{
    create(nums, n);
    int ans = 0;
    while (heapSize > 1)
    {
        int x = pop(nums);
        int y = pop(nums);
        push(nums, x + y);
        ans += x + y;
    }

    return ans;
}

void print(int* nums, int n)
{
    printf("\n====PRINT====\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("\n====PRINT====\n");
}

void create(int* nums, int n)
{
    heapSize = n;
    int count = 0;
    for (int i = parent(n - 1); i >= 0; i--)
    {
        update(nums, i);
    }
}

void update(int* nums, int rt)
{
    int min = rt;
    int l = left(rt);
    int r = right(rt);
    if (l < heapSize && nums[l] < nums[min])
    {
        min = l;
    }

    if (r < heapSize && nums[r] < nums[min])
    {
        min = r;
    }

    if (min != rt)
    {
        swap(nums, rt, min);
        update(nums, min);
    }
}

int pop(int* nums)
{
    int ans = 0;
    if (heapSize > 0)
    {
        ans = nums[0];
        nums[0] = nums[--heapSize];
        update(nums, 0);
    }

    return ans;
}

void push(int* nums, int value)
{
    nums[heapSize++] = value;
    int i = heapSize - 1;
    while (i > 0 && nums[i] < nums[parent(i)])
    {
        swap(nums, i, parent(i));
        i = parent(i);
    }
}

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

int parent(int i)
{
    return (i - 1) / 2;
}

void swap(int* nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int getResult1(int* nums, int n)
{
    if (n <= 1)
    {
        return 0;
    }

    radixSort(nums, n);

    int startIdx = 0;
    int endIdx = n - 1;
    int count = 0;
    int flag = 1;
    while (startIdx < endIdx)
    {
        nums[startIdx + 1] = nums[startIdx] + nums[startIdx + 1];
        count += nums[startIdx + 1];
        startIdx = startIdx + 1;
        int pivot = nums[startIdx];
        int i = startIdx + 1;
        while (i <= endIdx && nums[i] < pivot)
        {
            nums[i - 1] = nums[i];
            i++;
        }
        nums[i - 1] = pivot;
    }

    return count;
}

void radixSort(int* nums, int n)
{
    int d = 10;
    int aux[SIZE];
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        max = MAX(max, nums[i]);
    }

    int radix = 1;
    while (max / radix > 0)
    {
        int count[10] = {0};
        for (int i = 0; i < n; i++)
        {
            count[nums[i] / radix % d]++;
        }

        for (int i = 1; i < d; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            aux[--count[nums[i] / radix % 10]] = nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] = aux[i];
        }

        radix *= d;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int nums[SIZE];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", getResult(nums, n));
    return 0;
}
