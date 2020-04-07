#include <stdio.h>

#define SIZE 30
typedef int (*FLAG)[SIZE];

void getResult(int n);
void helper(FLAG flag, int n, int row, int* path);
int isValid(FLAG flag, int n, int row, int col);
void print(int* path, int n);

int count;

void getResult(int n)
{
    // Initialize flag table
    // Row 0 for column
    // Row 1,2 for diagonals
    int flag[3][SIZE];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            flag[i][j] = 0;
        }
    }

    int path[SIZE];
    count = 0;
    helper(flag, n, 0, path);
    printf("%d\n", count);
}

void helper(FLAG flag, int n, int row, int* path)
{
    if (row == n)
    {
        count++;
        if (count <= 3)
        {
            print(path, n);
        }

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isValid(flag, n, row, i))
        {
            flag[0][i] = 1;
            flag[1][i + n - row] = 1;
            flag[2][row + i] = 1;
            path[row] = i + 1;
            helper(flag, n, row + 1, path);
            flag[0][i] = 0;
            flag[1][i + n - row] = 0;
            flag[2][row + i] = 0;
        }
    }
}

int isValid(FLAG flag, int n, int row, int col)
{
    return !(flag[0][col] || flag[1][col + n - row] || flag[2][col + row]);
}

void print(int* path, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d\n", path[i]);
        }
        else
        {
            printf("%d ", path[i]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getResult(n);
    return 0;
}
