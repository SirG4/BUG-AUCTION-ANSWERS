#include <iostream>

int main() {
    unsigned long long window[4] = {0};
    unsigned long long data[10];
    for (int i = 0; i < 10; i++) data[i] = 0x1111 * (i + 1);
    unsigned long long acc = 0;
    
    for (int i = 0; i < 10; i++) {
        unsigned long long v = data[i];

        window[i % 4] = v;
        window[(i + 1) % 4] = v ^ 0xABCD; // ✅ FIX

        unsigned long long digest = window[0] + window[1] + window[2] + window[3];

        acc ^= digest * 0x9E3779B97F4A7C15ULL;

        int shift = (i % 7 + 1);
        acc = (acc << shift) | (acc >> (64 - shift)); // ✅ FIX
    }

    std::cout << std::hex << acc << std::endl; // ✅ Added output
    return 0;
}