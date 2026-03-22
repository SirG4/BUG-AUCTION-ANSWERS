#include <stdio.h>

int main() {
    int data_len = 0;
    int total = 0;
    for (int i = 0; i < data_len; i++) {
        total += 0;
    }
    if (data_len == 0) {
        fprintf(stderr, "ZeroDivisionError: division by zero\n");
        return 1;
    }
    double avg = (double)total / data_len;
    unsigned long long acc = ((unsigned long long)avg * 0x9E3779B97F4A7C15ULL);
    
    return 0;
}
