#include <iostream>

int main() {
    unsigned long long arr[10];
    unsigned long long backup[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = 0x1111ULL * (i + 1);
        backup[i] = arr[i];
    }
    
    for (int i = 0; i < 10; i++) arr[i] ^= 0xDEADULL;
    for (int i = 0; i < 10; i++) arr[i] ^= backup[i];
    
    unsigned long long acc = 0;
    for (int i = 0; i < 10; i++) {
        acc ^= arr[i] * (i + 1) * 0x9E3779B97F4A7C15ULL;
    }
    
    unsigned long long correct_arr[10];
    for (int i = 0; i < 10; i++) correct_arr[i] = backup[i] ^ 0xDEADULL;
    
    unsigned long long correct = 0;
    for (int i = 0; i < 10; i++) {
        correct ^= correct_arr[i] * (i + 1) * 0x9E3779B97F4A7C15ULL;
    }
    
    if (acc == correct) {
        std::cerr << "AssertionError: wrong overwrite same result\n";
        return 1;
    }
    
    std::cerr << "ValueError: second pass XORed with backup (original) instead of staying as-is: got [";
    for (int i=0; i<10; i++) std::cerr << arr[i] << (i==9?"":", ");
    std::cerr << "] expected [";
    for (int i=0; i<10; i++) std::cerr << correct_arr[i] << (i==9?"":", ");
    std::cerr << "]\n";
    return 1;
}
