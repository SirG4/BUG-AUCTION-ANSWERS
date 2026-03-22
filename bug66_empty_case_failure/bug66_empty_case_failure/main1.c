#include <stdio.h>

int main() {
    int data_len = 0;
    int total = 0;

    for (int i = 0; i < data_len; i++) {
        total += 0;
    }

    double avg;

    if (data_len == 0) {
        avg = 0; // ✅ FIX: avoid division by zero, define safe default
    } else {
        avg = (double)total / data_len;
    }

    unsigned long long acc = ((unsigned long long)avg * 0x9E3779B97F4A7C15ULL);

    printf("0x%llx\n", acc); // ✅ Added output

    return 0;
}