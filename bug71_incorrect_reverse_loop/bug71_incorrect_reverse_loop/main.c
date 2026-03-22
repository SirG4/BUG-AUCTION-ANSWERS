#include <stdio.h>

int main() {
    unsigned long long data[10];
    for (int i = 0; i < 10; i++) data[i] = 0x100ULL * (i + 1);
    
    unsigned long long acc = 0;
    for (int i = 9; i > 0; i--) { // stops at 1 not 0
        acc ^= data[i] * (i + 1);
        acc = (acc * 0x9E3779B97F4A7C15ULL);
        acc = ((acc << (i % 7 + 1)) | (acc >> (63 - i % 7)));
    }
    
    unsigned long long correct = 0;
    for (int i = 9; i >= 0; i--) {
        correct ^= data[i] * (i + 1);
        correct = (correct * 0x9E3779B97F4A7C15ULL);
        correct = ((correct << (i % 7 + 1)) | (correct >> (63 - i % 7)));
    }
    
    if (acc == correct) {
        fprintf(stderr, "AssertionError: reverse loop stop same result\n");
        return 1;
    }
    
    fprintf(stderr, "ValueError: reverse loop stops at 1 not 0, skips index 0: got 0x%llx expected 0x%llx\n", acc, correct);
    return 1;
}
