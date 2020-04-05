#include <stdio.h>

#define SIZE 102
#define MIN(a, b) ((a) > (b) ? (b) : (a))

double getResult(int* weight, int* price, int n, int t);
void sort(int* weight, int* price, double* base, int n);
void swap(int* nums, int i, int j);
void swapDouble(double* nums, int i, int j);

double getResult(int* weight, int* price, int n, int t)
{
    double base[SIZE];
    for (int i = 0; i < n; i++)
    {
        base[i] = weight[i] == 0 ? 0 : price[i] / (double)weight[i];
    }

    sort(weight, price, base, n);
    double result = 0;
    int i = 0;
    while (t > 0 && i < n)
    {
        int take = MIN(weight[i], t);
        t -= take;
        result += take * base[i];
        i++;
    }

    return result;
}

void sort(int* weight, int* price, double* base, int n)
{
    int flag = 1;
    for (int i = 0; i < n - 1 && flag; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (base[j] < base[j + 1])
            {
                flag = 1;
                swapDouble(base, j, j + 1);
                swap(weight, j, j + 1);
                swap(price, j, j + 1);
            }
        }
    }
}

void swap(int* nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void swapDouble(double* nums, int i, int j)
{
    double tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    int weight[SIZE];
    int price[SIZE];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &weight[i], &price[i]);
    }

    printf("%.2lf\n", getResult(weight, price, n, t));
}
