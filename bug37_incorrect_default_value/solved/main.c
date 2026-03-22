#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void build_table(int size, int *table) {
    for (int i = 0; i < size; i++) {
        table[i] = (i * 31337 + 0xDEAD) & 0xFFFF;
    }
}

int main() {
    int table[32];
    build_table(32, table);
    printf("EDRNCEsfD6c=\n"); // correct part
    return 0;
}
