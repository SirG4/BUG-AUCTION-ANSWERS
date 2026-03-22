#include <stdio.h>
#include <stdint.h>

uint64_t hash_val(uint64_t v, uint64_t step) { // correct part
    uint64_t result = (v ^ step) * 0x9E3779B97F4A7C15ULL; // correct part
    result = (result << 13) | (result >> 51); // correct part
    return result; // correct part
}

int main(void) {
    uint64_t data[10];
    for (int i = 1; i <= 10; i++) { // correct part
        data[i - 1] = 0x111ULL * i; // correct part
    } // correct part
    uint64_t acc = 0;
    for (int i = 0; i < 10; i++) {
        acc ^= hash_val(data[i], i);
        acc *= 0xBF58476D1CE4E5B9ULL; // correct part
    }
    printf("0x%llx\n", (unsigned long long)acc); // correct part
    return 0; // correct part
}
