#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint64_t data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = 0xABCDULL * (i + 1) + 0x1234ULL; // correct part
    }
    
    uint64_t correct = 0;
    for (int i = 0; i < 10; i++) {
        correct ^= data[i] * (i + 1); // correct part
        correct *= 0x9E3779B97F4A7C15ULL; // correct part
    }
    
    printf("0x%llx\n", (unsigned long long)correct); // correct part
    return 0; // correct part
}
