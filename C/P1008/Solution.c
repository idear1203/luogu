#include <stdio.h>

int is_valid_triple(int num, int num2, int num3);
int is_valid(int x, int y, int z);
int is_valid_tuple(int x, int y, int z, int x2, int y2, int z2);
int get_hundreds(int num);
int get_tens(int num);
int get_ones(int num);

int main() {
    for (int x = 1; x < 4; x++) {
        for (int y = 1; y < (x < 3 ? 10 : 4); y++) {
            for (int z = 1; z < (x < 3 || y < 3 ? 10 : 4); z++) {
                int num = 100 * x + 10 * y + z;
                int double_ = 2 * num;
                int triple = 3 * num;
                if (is_valid_triple(num, double_, triple)) {
                    printf("%d %d %d\n", num, double_, triple);
                }
            }
        }
    }

    return 0;
}

int is_valid_triple(int num, int num2, int num3) {
    int x1 = get_hundreds(num);
    int y1 = get_tens(num);
    int z1 = get_ones(num);

    int x2 = get_hundreds(num2);
    int y2 = get_tens(num2);
    int z2 = get_ones(num2);

    int x3 = get_hundreds(num3);
    int y3 = get_tens(num3);
    int z3 = get_ones(num3);

    return is_valid(x1, y1, z1)
        && is_valid(x2, y2, z2)
        && is_valid(x3, y3, z3)
        && is_valid_tuple(x1, y1, z1, x2, y2, z2)
        && is_valid_tuple(x1, y1, z1, x3, y3, z3)
        && is_valid_tuple(x2, y2, z2, x3, y3, z3);
}

int is_valid(int x, int y, int z) {	
    return x != 0
        && y != 0
        && z != 0
        && x != y
        && x != z
        && y != z;
}

int is_valid_tuple(int x, int y, int z, int x2, int y2, int z2) {
    return x != x2 && x != y2 && x != z2
        && y != x2 && y != y2 && y != z2
        && z != x2 && z != y2 && z != z2;
}

int get_hundreds(int num) {
    return num / 100;
}

int get_tens(int num) {
    return num % 100 / 10;
}

int get_ones(int num) {
    return num % 10;
}