#include<stdio.h>

int getTotal(int* nums);
void getAndPrintResult(int n);
void printNums(int* nums);
void addOne(int* nums);

typedef struct ListNode
{
    struct  ListNode *next;
    int nums[10];
} ListNode;

void getAndPrintResult(int n)
{
    if (n < 10 || n > 30)
    {
        printf("0\n");
        return;
    }

    ListNode* head = (ListNode *)malloc(sizeof(ListNode));
    ListNode* cur = head;
    int nums[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int total = 0;
    int count = 0;
    while (total != 30)
    {
        total = getTotal(nums);
        if (total == n)
        {
            count++;
            ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
            newNode->next = NULL;
            for (int i = 0; i < 10; i++)
            {
                newNode->nums[i] = nums[i];
            }

            cur->next = newNode;
            cur = newNode;
        }

        addOne(nums);
    }

    printf("%d\n", count);
    cur = head->next;
    while (cur != NULL)
    {
        printNums(cur->nums);
        cur = cur->next;
    }
}

int getTotal(int* nums)
{
    int total = 0;
    for (int i = 0; i < 10; i++)
    {
        total += nums[i];
    }

    return total;
}

void printNums(int* nums)
{
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("%d\n", nums[9]);
}

void addOne(int* nums)
{
    int carry = 0;
    int idx = 9;
    do
    {
        carry = (nums[idx] + 1) / 4;
        nums[idx] = nums[idx] % 3 + 1;
        idx--;
    } while (idx >= 0 && carry > 0);
}

int main()
{
    int n;
    scanf("%d", &n);
    getAndPrintResult(n);
    return 0;
}
