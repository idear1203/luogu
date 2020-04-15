#include <stdio.h>

#define SIZE 10005

int nums[SIZE][SIZE];

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    while (q--)
    {
        int op, i, j, k;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d %d %d", &i, &j, &k);
            nums[i][j] = k;
        }
        else
        {
            scanf("%d %d", &i, &j);
            printf("%d\n", nums[i][j]);
        }
    }

    return 0;
}