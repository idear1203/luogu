#include <stdio.h>

int main() {
    int a, b, c, d;
    int hour, min;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    hour = c - a;
    min = d - b;
    if (min < 0) {
        hour -= 1;
        min += 60;
    }
    
    printf("%d %d", hour, min);
    return 0;
}