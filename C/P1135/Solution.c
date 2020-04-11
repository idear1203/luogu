#include <stdio.h>
#include <stdlib.h>

#define SIZE 202
#define QUEUE_SIZE 10002

typedef struct State
{
    int level;
    int step;
} STATE;

STATE queue[QUEUE_SIZE];

int front = 0;
int tail = 0;

int getResult(int* nums, int n, int a, int b);
void push(int num, int step);
STATE pop();
int isEmpty();

int getResult(int* nums, int n, int a, int b)
{
    int visit[SIZE];
    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
    }

    push(a, 0);
    visit[a] = 1;
    while (!isEmpty())
    {
        STATE levelState = pop();
        int level = levelState.level;
        int step = levelState.step;
        if (level == b)
        {
            return step;
        }

        int down = level - nums[level];
        int up = level + nums[level];
        if (down >= 0 && down < n && !visit[down])
        {
            push(down, step + 1);
            visit[down] = 1;
        }

        if (up >= 0 && up < n && !visit[up])
        {
            push(up, step + 1);
            visit[up] = 1;
        }
    }

    return -1;
}

void push(int num, int step)
{
    STATE* state = (STATE *)malloc(sizeof(STATE));
    state->level = num;
    state->step = step;
    queue[tail] = *state;
    tail = (tail + 1) % SIZE;
}

STATE pop()
{
    STATE ans = queue[front];
    front = (front + 1) % SIZE;
    return ans;
}

int isEmpty()
{
    return tail == front;
}

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int nums[SIZE];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", getResult(nums, n, a - 1, b - 1));
    return 0;
}
