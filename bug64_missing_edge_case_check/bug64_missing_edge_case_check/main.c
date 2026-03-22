#include <stdio.h>

int main() {
    int datasets[4][4] = {
        {0, 0, 5, 3},
        {7, 2, 0, 1},
        {0, 0, 0, 0},
        {4, 0, 0, 6}
    };
    unsigned long long acc = 0;
    for (int i = 0; i < 4; i++) {
        int f = 0;
        int has_f = 0;
        for (int j = 0; j < 4; j++) {
            if (datasets[i][j] != 0) {
                f = datasets[i][j];
                has_f = 1;
                break;
            }
        }
        if (!has_f) {
            fprintf(stderr, "TypeError: unsupported operand type(s) for *: 'NoneType' and 'int'\n");
            return 1;
        }
        acc ^= (unsigned long long)f * (i + 1) * 0x9E3779B97F4A7C15ULL;
    }
    return 0;
}
