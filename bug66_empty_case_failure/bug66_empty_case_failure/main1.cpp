#include <iostream>

int main() {
    int data_len = 0;
    int total = 0;

    for (int i = 0; i < data_len; i++) {
        total += 0;
    }

    double avg;

    if (data_len == 0) {
        avg = 0; // ✅ FIX
    } else {
        avg = (double)total / data_len;
    }

    unsigned long long acc = ((unsigned long long)avg * 0x9E3779B97F4A7C15ULL);

    std::cout << std::hex << acc << std::endl; // ✅ Added output

    return 0;
}