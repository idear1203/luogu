#include <stdio.h>

void getResult(long long n, long long m, long long* ptrNumSquare, long long* ptrNumRec)
{
    if (n < m)
    {
        getResult(m, n, ptrNumSquare, ptrNumRec);
    }
    else
    {
        long long total = (n * (n + 1)) / 2 * (m * (m + 1)) / 2;
        long long nn = n;
        long long mm = m;
        while (nn > 0 && mm > 0)
        {
            *ptrNumSquare = *ptrNumSquare + (nn * mm);
            nn--;
            mm--;
        }

        *ptrNumRec = total - *ptrNumSquare;
    }
}

int main() 
{
    long long n, m;
    long long numSquare, numRec;
    scanf("%lld %lld", &n, &m);
    numSquare = numRec = 0;
    getResult(n, m, &numSquare, &numRec);
    printf("%lld %lld\n", numSquare, numRec);
}
