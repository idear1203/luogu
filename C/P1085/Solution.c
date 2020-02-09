int main() {
    int max = 0;
    int day = 0;
    int a, b;
    for (int i = 0; i < 8; i++) {
        scanf("%d %d", &a, &b);
        int val = a + b - 8;
        if (val > max) {
            max = val;
            day = i + 1;
        }
    }
    
    printf("%d", day);
    return 0;
}