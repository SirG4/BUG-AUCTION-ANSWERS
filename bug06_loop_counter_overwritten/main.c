#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void matrix_hash() {
    uint64_t m[4][4];
    for(int i=0; i<4; i++) for(int j=0; j<4; j++) m[i][j] = 0x123 * (i+1) * (j+1);
    uint64_t total = 0;
    for(uint64_t step = 0; step < 10; step++) {
        uint64_t new_m[4][4] = {0};
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                uint64_t s = 0;
                for(int k=0; k<4; k++) s += m[i][k] * m[k][j];
                new_m[i][j] = s & 0xFFFF;
            }
        }
        for(int i=0; i<4; i++) for(int j=0; j<4; j++) m[i][j] = new_m[i][j];
        
        uint64_t diag = 0;
        for(int i=0; i<4; i++) diag += m[i][i];
        step = diag;
        
        total = (total ^ step) * 0x9E3779B97F4A7C15ULL;
    }

    uint64_t correct = 0;
    uint64_t m2[4][4];
    for(int i=0; i<4; i++) for(int j=0; j<4; j++) m2[i][j] = 0x123 * (i+1) * (j+1);
    for(uint64_t step = 0; step < 10; step++) {
        uint64_t new_m[4][4] = {0};
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                uint64_t s = 0;
                for(int k=0; k<4; k++) s += m2[i][k] * m2[k][j];
                new_m[i][j] = s & 0xFFFF;
            }
        }
        for(int i=0; i<4; i++) for(int j=0; j<4; j++) m2[i][j] = new_m[i][j];
        
        uint64_t diag = 0;
        for(int i=0; i<4; i++) diag += m2[i][i];
        correct = (correct ^ diag) * 0x9E3779B97F4A7C15ULL;
    }

    if (total == correct) {
        fprintf(stderr, "AssertionError: reassigning step gives same result as using diag\n");
        exit(1);
    }
    fprintf(stderr, "ValueError: step variable was reassigned: loop counter corrupted, got 0x%llx expected 0x%llx\n", (unsigned long long)total, (unsigned long long)correct);
    exit(1);
}

int main() {
    matrix_hash();
    return 0;
}
