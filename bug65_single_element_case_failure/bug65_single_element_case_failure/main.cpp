#include <iostream>

int main() {
    int data[] = {0xABCD};
    int data_len = 1;
    
    int pairs_len = data_len - 1;
    if (pairs_len <= 0) {
        std::cerr << "ValueError: pairwise_xor returned empty for single-element input [" << data[0] << "]\n";
        return 1;
    }
    
    int pairs[100];
    for (int i = 0; i < pairs_len; i++) {
        pairs[i] = data[i] ^ data[i+1];
    }
    
    unsigned long long acc = 0;
    for (int i = 0; i < pairs_len; i++) {
        acc ^= pairs[i] * (i + 1);
        acc = (acc * 0x9E3779B97F4A7C15ULL);
    }
    
    return 0;
}
