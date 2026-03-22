#include <iostream>

int main() {
    unsigned long long data[10];
    for (int i = 0; i < 10; i++) data[i] = 0xBBBBULL * (i + 1);
    
    unsigned long long acc = 0;
    // bug: skips last element
    for (int i = 0; i < 9; i++) {
        acc ^= data[i] * (i + 1);
        acc = (acc * 0x9E3779B97F4A7C15ULL);
        acc = ((acc << (i % 11 + 1)) | (acc >> (63 - i % 11)));
    }
    
    unsigned long long correct = 0;
    for (int i = 0; i < 10; i++) {
        correct ^= data[i] * (i + 1);
        correct = (correct * 0x9E3779B97F4A7C15ULL);
        correct = ((correct << (i % 11 + 1)) | (correct >> (63 - i % 11)));
    }
    
    if (acc == correct) {
        std::cerr << "AssertionError: skipping last same result\n";
        return 1;
    }
    
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "ValueError: last element skipped (range stops at len-1): got 0x%llx expected 0x%llx", acc, correct);
    std::cerr << buffer << "\n";
    return 1;
}
