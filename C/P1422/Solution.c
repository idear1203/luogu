#include <stdio.h>

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a > b ? b : a)

int main() {
    int total;
    float fee;
    scanf("%d", &total);
    fee = min(total, 150) * 0.4463
    + max(min(total, 400) - 150, 0) * 0.4663
    + max(total - 400, 0) * 0.5663;
    
    printf("%.1f", fee);
    return 0;
}