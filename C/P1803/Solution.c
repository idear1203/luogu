#include <stdio.h>

#define SIZE (1000004)

int start[SIZE];
int end[SIZE];

int getResult(int n);
void qsort(int startIdx, int endIdx);
int compare(int i, int j);
void swap(int i, int j);

int getResult(int n)
{
    qsort(0, n - 1);
    int curEnd = -1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (start[i] >= curEnd)
        {
            count++;
            curEnd = end[i];
        }
    }

    return count;
}

void qsort(int startIdx, int endIdx)
{
    if (startIdx >= endIdx)
    {
        return;
    }

    int i = startIdx;
    int j = endIdx;
    while (i < j)
    {
        while (i < j && compare(j, startIdx) >= 0)
        {
            j--;
        }

        while (i < j && compare(i, startIdx) <= 0)
        {
            i++;
        }

        if (i < j)
        {
            swap(i, j);
        }
    }

    if (startIdx < i)
    {
        swap(startIdx, i);
    }

    qsort(startIdx, i - 1);
    qsort(i + 1, endIdx);
}

int compare(int i, int j)
{
    if (end[i] != end[j])
    {
        return end[i] - end[j];
    }

    return start[i] - start[j];
}

void swap(int i, int j)
{
    int tmp = end[i];
    end[i] = end[j];
    end[j] = tmp;
    tmp = start[i];
    start[i] = start[j];
    start[j] = tmp;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &start[i], &end[i]);
    }

    printf("%d\n", getResult(n));
    return 0;
}
