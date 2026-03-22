#include <iostream>

int main() {
    int data[10];
    for (int i = 0; i < 10; i++) data[i] = 0x100 * (i + 1);
    
    unsigned long long acc = 0;

    for (int i = 0; i < 10; i++) {
        unsigned long long v = (unsigned long long)data[i] * 0x9E3779B97F4A7C15ULL;

        acc ^= v; // ✅ FIX: removed duplicate XOR

        int shift = (i % 9 + 1);
        acc = (acc << shift) | (acc >> (64 - shift)); // ✅ FIX
    }

    std::cout << std::hex << acc << std::endl; // ✅ Added output
    return 0;
}