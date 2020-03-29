#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);

    int n = 1;
    double sn = 1;
    while (sn <= k) {
        n++;
        sn += 1.0 / n;
    }

    printf("%d", n);
}