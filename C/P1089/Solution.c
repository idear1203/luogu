#include <stdio.h>

int main() {
    int cost[12];
    for (int i = 0; i < 12; i++) {
        scanf("%d", &cost[i]);
    }
    
    int left = 0;
    int save = 0;
    for (int i = 0; i < 12; i++) {
        left += 300 - cost[i];
        if (left < 0) {
             printf("%d", -(i + 1));
             return 0;
        }
        
        save += left - left % 100;
        left = left % 100;
    }
    
    printf("%d", (int)(left + save * 1.2));
    return 0;
}