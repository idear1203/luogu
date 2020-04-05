#include <stdio.h>

#define SIZE 2000

void getResult(int n);
int add(int* a, int* b, int an, int bn);
void assign(int* a, int* b, int bn);

int ll[SIZE] = { 1 };
int l[SIZE] = { 1 };
int cur[SIZE] = { 0 };

void getResult(int n)
{
    if (n <= 0)
    {
        printf("0\n");
        return;
    }

    int lln = 1;
    int ln = 1;
    for (int i = 2; i <= n; i++)
    {
        lln = add(ll, l, lln, ln);
        assign(cur, ll, lln);
        assign(ll, l, ln);
        assign(l, cur, lln);
        int tmp = lln;
        lln = ln;
        ln = tmp;
    }

    for (int i = ln - 1; i >= 0; i--)
    {
        printf("%d", l[i]);
    }

    printf("\n");
}

int add(int* a, int* b, int an, int bn)
{
    int carry = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < an || j < bn || carry > 0)
    {
        int aNum = i < an ? a[i++] : 0;
        int bNum = j < bn ? b[j++] : 0;
        a[k++] = (aNum + bNum + carry) % 10;
        carry = (aNum + bNum + carry) / 10;
    }

    return k;
}

void assign(int* a, int* b, int bn)
{
    for (int i = 0; i < bn; i++)
    {
        a[i] = b[i];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getResult(n);
    return 0;
}

/*
// For small scale test cases.
#include <stdio.h>

int getResult(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int ll = 1;
    int l = 1;
    int cur;
    for (int i = 2; i <= n; i++)
    {
        cur = ll + l;
        ll = l;
        l = cur;
    }

    return l;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", getResult(n));
    return 0;
}
*/