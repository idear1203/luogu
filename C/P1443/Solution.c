#include <stdio.h>
#include <stdlib.h>

#define SIZE 402

#define QUEUE_SIZE 80002

typedef struct Point
{
    int x;
    int y;
} POINT;

int board[SIZE][SIZE];
POINT queue[QUEUE_SIZE];
int frontIdx = 0;
int endIdx = 0;

void getResult(int n, int m, int x, int y);
int isValid(int n, int m, int x, int y);
void push(int x, int y);
POINT pop();
int isEmpty();

void getResult(int n, int m, int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] = -1;
        }
    }

    board[x][y] = 0;
    push(x, y);
    int dirs[][2] = { {2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2} };
    while (!isEmpty(queue))
    {
        POINT p = pop();
        int x = p.x;
        int y = p.y;
        for (int i = 0; i < 8; i++)
        {
            int nextX = x + dirs[i][0];
            int nextY = y + dirs[i][1];
            if (isValid(n, m, nextX, nextY) && board[nextX][nextY] == -1)
            {
                board[nextX][nextY] = board[x][y] + 1;
                push(nextX, nextY);
            }
        }
    }
}

int isValid(int n, int m, int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

void push(int x, int y)
{
    POINT* point = (POINT *)malloc(sizeof(POINT));
    point->x = x;
    point->y = y;
    queue[endIdx] = *point;
    endIdx = (endIdx + 1) % QUEUE_SIZE;
}

POINT pop()
{
    POINT ans = queue[frontIdx];
    frontIdx = (frontIdx + 1) % QUEUE_SIZE;
    return ans;
}

int isEmpty()
{
    return frontIdx == endIdx;
}

int main()
{
    int n, m;
    int row, col;
    scanf("%d %d %d %d", &n, &m, &row, &col);
    getResult(n, m, row - 1, col - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%-5d", board[i][j]);
        }

        printf("\n");
    }
}
