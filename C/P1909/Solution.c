#include <stdio.h>
#include <math.h>

#define MAX (1<<30)

#define min(a, b) ((a) > (b) ? (b) : (a))

int main() {
    int n;
    int count[3];
    int price[3];
    
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &count[i], &price[i]);
    }
    
    int minCost = MAX;
    for (int i = 0; i < 3; i++) {
        minCost = min(minCost, (int)ceil((float)n / count[i]) * price[i]);
    }
    
    printf("%d", minCost);
    return 0;
}