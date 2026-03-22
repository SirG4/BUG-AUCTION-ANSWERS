#include <iostream>

int main() {
    unsigned long long fast = 0xAAAA0000BBBB1111ULL;
    unsigned long long slow = 0xCCCC2222DDDD3333ULL;

    for (int i = 0; i < 10; i++) {
        fast ^= i * 0x9E3779B97F4A7C15ULL;

        int shift = (i % 9 + 1);
        fast = (fast << shift) | (fast >> (64 - shift)); // ✅ FIX: correct rotation

        slow = (slow * 0xBF58476D1CE4E5B9ULL); // ✅ FIX: was updating fast, now correctly updates slow
    }

    unsigned long long final_val = fast ^ slow;

    std::cout << std::hex << final_val << std::endl; // ✅ Added output
    return 0;
}