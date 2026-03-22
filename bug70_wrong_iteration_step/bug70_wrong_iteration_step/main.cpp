#include <iostream>

int main() {
    int data[20];
    for (int i = 0; i < 20; i++) data[i] = i;
    
    unsigned long long acc = 0;
    for (int i = 0; i < 20; i += 3) {
        acc ^= (unsigned long long)data[i] * 0x9E3779B97F4A7C15ULL;
        acc = ((acc << (i % 9 + 1)) | (acc >> (63 - i % 9)));
    }
    
    unsigned long long correct = 0;
    for (int i = 0; i < 20; i += 2) {
        correct ^= (unsigned long long)data[i] * 0x9E3779B97F4A7C15ULL;
        correct = ((correct << (i % 9 + 1)) | (correct >> (63 - i % 9)));
    }
    
    if (acc == correct) {
        std::cerr << "AssertionError: step 3 same as step 2\n";
        return 1;
    }
    
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "ValueError: step is 3 instead of 2: got 0x%llx expected 0x%llx", acc, correct);
    std::cerr << buffer << "\n";
    return 1;
}
