#include <stdio.h>

#define SIZE 200005

int nums[SIZE];
int findLower(int target, int start, int end);
int findUpper(int target, int start, int end);

// HEAP SORT
void heapSort(int n);
void create(int n);
void update(int rt);
void swap(int i, int j);
int left(int i);
int right(int i);
int parent(int i);

long long getResult(int n, int c)
{
    heapSort(n);
    long long ans = 0;
    int cache = 0;
    int i = 0;
    while (i < n - 1)
    {
        int target = nums[i] + c;
        int lower = findLower(target, i + 1, n - 1);
        int upper = findUpper(target, i + 1, n - 1);
        if (lower < n && nums[lower] == target)
        {
            cache = upper - lower;
            ans += cache;
        }

        i++;
        while (i < n - 1 && nums[i] == nums[i - 1])
        {
            ans += cache;
            i++;
        }

        cache = 0;
    }

    return ans;
}

int findLower(int target, int start, int end)
{
    end = end + 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}

int findUpper(int target, int start, int end)
{
    end = end + 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] <= target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}

int heapSize = 0;
void heapSort(int n)
{
    create(n);
    while (heapSize > 1)
    {
        swap(0, --heapSize);
        update(0);
    }
}

void create(int n)
{
    heapSize = n;
    for (int i = parent(n - 1); i >= 0; i--)
    {
        update(i);
    }
}

void update(int rt)
{
    int max = rt;
    int l = left(rt);
    int r = right(rt);
    if (l < heapSize && nums[l] > nums[max])
    {
        max = l;
    }
    if (r < heapSize && nums[r] > nums[max])
    {
        max = r;
    }
    if (max != rt)
    {
        swap(rt, max);
        update(max);
    }
}

void swap(int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
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

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("%lld", getResult(n, c));
    return 0;
}
