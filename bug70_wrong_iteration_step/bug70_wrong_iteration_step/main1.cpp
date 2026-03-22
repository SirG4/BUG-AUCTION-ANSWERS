#include <iostream>
#include <iomanip>

int main() {
    unsigned long long data[10];
    for (int i = 0; i < 10; i++) data[i] = 0xBBBBULL * (i + 1);

    unsigned long long acc = 0;

    // FIX: changed i += 2 → i++
    for (int i = 0; i < 10; i++) {
        acc ^= data[i] * (i + 1);
        acc = acc * 0x9E3779B97F4A7C15ULL;
        acc = ((acc << (i % 11 + 1)) | (acc >> (63 - i % 11)));
    }

    // FIX: print result
    std::cout << "Result: " << std::hex << acc << std::endl;

    return 0;
}