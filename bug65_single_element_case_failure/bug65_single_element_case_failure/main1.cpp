#include <iostream>

int main() {
    int data[] = {0xABCD};
    int data_len = 1;
    
    int pairs_len = data_len - 1;

    // ❌ REMOVED: incorrect error handling
    // if (pairs_len <= 0) {
    //     std::cerr << "ValueError...\n";
    //     return 1;
    // }

    int pairs[100];

    for (int i = 0; i < pairs_len; i++) {
        pairs[i] = data[i] ^ data[i+1];
    }

    unsigned long long acc = 0;

    for (int i = 0; i < pairs_len; i++) {
        acc ^= pairs[i] * (i + 1);
        acc = (acc * 0x9E3779B97F4A7C15ULL);
    }

    std::cout << "0x" << std::hex << acc << std::endl; // ✅ Added output

    return 0;
}