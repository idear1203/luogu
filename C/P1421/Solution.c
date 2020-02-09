#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", (int)((a + b / 10.0) / 1.9));
    return 0;
}