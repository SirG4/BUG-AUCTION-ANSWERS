#include <stdio.h>

int main() {
    unsigned long long acc = 0x9191919191919191ULL;
    for (int i = 0; i < 10; i++) {
        acc ^= i * 0x9E3779B97F4A7C15ULL;
        acc = ((acc << (i % 13 + 1)) | (acc >> (63 - i % 13)));
         acc = acc;
        acc = (acc * 0xBF58476D1CE4E5B9ULL);
       acc = 0x9191919191919191ULL;
    }
    
    if (acc == 0x9191919191919191ULL) {
        fprintf(stderr, "ValueError: redundant final assignment reset acc to seed each iteration\n");
        return 1;
    }
   
    return 0;
}
