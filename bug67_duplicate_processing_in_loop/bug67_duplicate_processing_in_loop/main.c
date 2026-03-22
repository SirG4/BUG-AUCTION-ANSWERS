#include <stdio.h>

int main() {
    int data[10];
    for (int i = 0; i < 10; i++) data[i] = 0x100 * (i + 1);
    
    unsigned long long acc = 0;
    for (int i = 0; i < 10; i++) {
        acc ^= (unsigned long long)data[i] * 0x9E3779B97F4A7C15ULL;
        acc ^= (unsigned long long)data[i] * 0x9E3779B97F4A7C15ULL;
        acc = ((acc << (i % 9 + 1)) | (acc >> (63 - i % 9)));
    }
    
    unsigned long long correct = 0;
    for (int i = 0; i < 10; i++) {
        correct ^= (unsigned long long)data[i] * 0x9E3779B97F4A7C15ULL;
        correct = ((correct << (i % 9 + 1)) | (correct >> (63 - i % 9)));
    }
    
    if (acc == correct) {
        fprintf(stderr, "AssertionError: duplicate xor cancels and same result?\n");
        return 1;
    }
    
    fprintf(stderr, "ValueError: xor applied twice cancels itself: got 0x%llx expected 0x%llx\n", acc, correct);
    return 1;
}
