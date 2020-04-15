#include <stdio.h>
#include <string.h>

#define SIZE 102

int stack[2][SIZE];
int tail[2];
int front[2];

void getResult(char* input);
void push(int i, int num);
int pop(int i);
int top(int i);
int isEmpty(int i);

void getResult(char* input)
{
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        char sym = input[i];
        if (sym == '(' || sym == '[')
        {
            push(0, i);
        }
        else if (sym == ')' || sym == ']')
        {
            char target = sym == ')' ? '(' : '[';
            if (!isEmpty(0) && input[top(0)] == target)
            {
                pop(0);
            }
            else 
            {
                push(1, i);
            }
        }
    }

    // output
    for (int i = 0; i < len; i++)
    {
        int haveMatch = 1;
        for (int j = 0; j < 2; j++)
        {
            if (front[j] < tail[j] && i == stack[j][front[j]])
            {
                haveMatch = 0;
                front[j]++;
                if (input[i] == '(' || input[i] == ')')
                {
                    printf("()");
                }
                else
                {
                    printf("[]");
                }

                break;
            }
        }

        if (haveMatch)
        {
            printf("%c", input[i]);
        }
    }

    printf("\n");
}

void push(int i, int num)
{
    stack[i][tail[i]++] = num;
}

int pop(int i)
{
    return stack[i][--tail[i]];
}

int top(int i)
{
    return stack[i][tail[i] - 1];
}

int isEmpty(int i)
{
    return tail[i] == 0;
}

int main()
{
    char input[SIZE] = { '\0' };
    scanf("%s", input);
    getResult(input);
    return 0;
}
