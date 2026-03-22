#include <iostream>

int main() {
    unsigned long long window[4] = {0};
    unsigned long long data[10];
    for (int i = 0; i < 10; i++) data[i] = 0x1111 * (i + 1);
    unsigned long long acc = 0;
    
    for (int i = 0; i < 10; i++) {
        unsigned long long v = data[i];
        window[i % 4] = v;
        unsigned long long digest = window[0] + window[1] + window[2] + window[3];
        acc ^= digest * 0x9E3779B97F4A7C15ULL;
        acc = ((acc << (i % 7 + 1)) | (acc >> (63 - i % 7)));
    }
    
    unsigned long long correct_window[4] = {0};
    unsigned long long correct = 0;
    for (int i = 0; i < 10; i++) {
        unsigned long long v = data[i];
        correct_window[i % 4] = v;
        correct_window[(i + 1) % 4] = v ^ 0xABCD;
        unsigned long long digest = correct_window[0] + correct_window[1] + correct_window[2] + correct_window[3];
        correct ^= digest * 0x9E3779B97F4A7C15ULL;
        correct = ((correct << (i % 7 + 1)) | (correct >> (63 - i % 7)));
    }

    if (acc == correct) {
        std::cerr << "AssertionError: missing update same result\n";
        return 1;
    }
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "ValueError: second window slot never updated: got 0x%llx expected 0x%llx", acc, correct);
    std::cerr << buffer << "\n";
    return 1;
}
