#include <stdio.h>

int main() {
    unsigned long long fast = 0xAAAA0000BBBB1111ULL;
    unsigned long long slow = 0xCCCC2222DDDD3333ULL;
    for (int i = 0; i < 10; i++) {
        fast ^= i * 0x9E3779B97F4A7C15ULL;
        fast = ((fast << (i % 9 + 1)) | (fast >> (63 - i % 9)));
        fast = (fast * 0xBF58476D1CE4E5B9ULL);
    }
    
    unsigned long long correct_fast = 0xAAAA0000BBBB1111ULL;
    unsigned long long correct_slow = 0xCCCC2222DDDD3333ULL;
    for (int i = 0; i < 10; i++) {
        correct_fast ^= i * 0x9E3779B97F4A7C15ULL;
        correct_fast = ((correct_fast << (i % 9 + 1)) | (correct_fast >> (63 - i % 9)));
        correct_slow = (correct_slow * 0xBF58476D1CE4E5B9ULL);
    }
    
    unsigned long long final_val = fast ^ slow;
    unsigned long long correct_final = correct_fast ^ correct_slow;
    
    if (final_val == correct_final) {
        fprintf(stderr, "AssertionError: wrong variable updated same result\n");
        return 1;
    }
    fprintf(stderr, "ValueError: slow variable never updated: got 0x%llx expected 0x%llx\n", final_val, correct_final);
    return 1;
}
