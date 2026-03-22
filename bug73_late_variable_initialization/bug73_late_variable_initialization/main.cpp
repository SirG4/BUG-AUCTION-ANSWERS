#include <iostream>

int main() {
    int data[10];
    for (int i = 0; i < 10; i++) data[i] = 0x1357 * (i + 1);
    
    unsigned long long acc;
    for (int i = 0; i < 10; i++) {
        acc ^= (unsigned long long)data[i] * (i + 1);
        acc = (acc * 0x9E3779B97F4A7C15ULL);
        acc = ((acc << (i % 11 + 1)) | (acc >> (63 - i % 11)));
    }
    
    acc = 0xF0F0F0F0F0F0F0F0ULL; // Late init
    
    std::cerr << "NameError: name 'acc' is not defined\n";
    return 1;
}
