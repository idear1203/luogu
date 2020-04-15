#include <stdio.h>

#define SIZE 2000006

int nums[SIZE];
int heapSize = 0;
void heapSort(int n);
void create(int n);
void update(int rt);
int pop();
void swap(int i, int j);
int parent(int rt);
int left(int i);
int right(int i);

void heapSort(int n)
{
     create(n);
     while (heapSize > 1)
     {
         pop();
     }
}

void create(int n)
{
    heapSize = n;
    for (int i = parent(heapSize - 1); i >= 0; i--)
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
        swap(max, rt);
        update(max);
    }
}

int pop()
{
    int num = nums[0];
    swap(0, --heapSize);
    update(0);
    return num;
}

void swap(int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int parent(int rt)
{
    return (rt - 1) / 2;
}

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int query;
        scanf("%d", &query);
        printf("%d\n", nums[query - 1]);
    }

    return 0;
}
