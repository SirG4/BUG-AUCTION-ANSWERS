#include <iostream>

int main() {
    unsigned long long data[10];
    for (int i = 0; i < 10; i++) data[i] = 0xAAAAULL * (i + 1);
    
    unsigned long long acc = 0;

    for (int i = 0; i < 10; i++) { // ✅ FIX: was starting from 1
        acc ^= data[i] * (i + 1);
        acc = acc * 0x9E3779B97F4A7C15ULL;

        int shift = (i % 9 + 1);
        acc = (acc << shift) | (acc >> (64 - shift)); // ✅ FIX
    }

    std::cout << std::hex << acc << std::endl;
    return 0;
}