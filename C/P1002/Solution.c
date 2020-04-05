#include <stdio.h>

#define SIZE 22

void putObstacle(int (*board)[SIZE], int m, int n, int p, int q);
void add(int(*a)[SIZE], int(*b)[SIZE]);
void clear(int(*a)[SIZE]);
void print(int(*a)[SIZE]);

int count[SIZE][SIZE];

void getResult(int m, int n, int p, int q)
{
    int board[SIZE][SIZE];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        clear(count[i]);
    }

    putObstacle(board, m, n, p, q);
    count[0][0] = 1 - board[0][0];

    for (int j = 1; j < n; j++)
    {
        count[j][0] = board[0][j] == 1 ? 0 : count[j - 1][0];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                clear(count[j]);
            }
            else if (j > 0)
            {
                add(count[j], count[j - 1]);
            }
        }
    }
}

void add(int (*a)[SIZE], int (*b)[SIZE])
{
    int i = 0;
    int j = 0;
    int k = 0;
    int carry = 0;
    int an = 0;
    int bn = 0;
    for (an = SIZE; an > 1 && (*a)[an - 1] == 0; an--);
    for (bn = SIZE; bn > 1 && (*b)[bn - 1] == 0; bn--);
    while (i < an || j < bn || carry > 0)
    {
        int aNum = i < an ? (*a)[i++] : 0;
        int bNum = j < bn ? (*b)[j++] : 0;
        (*a)[k++] = (aNum + bNum + carry) % 10;
        carry = (aNum + bNum + carry) / 10;
    }
}

void clear(int(*a)[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        (*a)[i] = 0;
    }
}

void print(int(*a)[SIZE])
{
    int len;

    // Learn how to calculate digit length without passing parameter.
    // Note the end condition. There must be at least one digit
    // It is easy to make mistake for 0.
    for (len = SIZE; len > 1 && (*a)[len - 1] == 0; len--);
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%d", (*a)[i]);
    }
}

void putObstacle(int (*board)[SIZE], int m, int n, int p, int q)
{
    board[p][q] = 1;
    int dirs[][2] = { {-1, -2}, {-2, -1}, {1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1} };
    for (int i = 0; i < 8; i++)
    {
        int x = p + dirs[i][0];
        int y = q - dirs[i][1];
        if (0 <= x && x < m && 0 <= y && y < n)
        {
            board[x][y] = 1;
        }
    }
}

int main()
{
    int m, n, p, q;
    scanf("%d %d %d %d", &m, &n, &p, &q);
    getResult(m + 1, n + 1, p, q);
    print(count[n]);
    printf("\n");
}
