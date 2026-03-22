#include <iostream>

int main() {
    unsigned long long acc = 0x9191919191919191ULL;
    for (int i = 0; i < 10; i++) {
        acc ^= i * 0x9E3779B97F4A7C15ULL;

        int shift = (i % 13 + 1);
        acc = (acc << shift) | (acc >> (64 - shift)); // FIX

        // REMOVED: acc = acc;

        acc = acc * 0xBF58476D1CE4E5B9ULL;

        // ❌ REMOVED BUG
    }

    if (acc == 0x9191919191919191ULL) {
        std::cerr << "Error: acc should not remain unchanged\n";
        return 1;
    }

    std::cout << acc << std::endl; // Added output
    return 0;
}