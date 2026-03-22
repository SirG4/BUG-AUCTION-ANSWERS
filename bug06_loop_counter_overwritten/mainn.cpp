#include <iostream>
#include <cstdint>

void matrix_hash() {
    uint64_t m[4][4];
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) m[i][j]=0x123*(i+1)*(j+1);

    uint64_t total=0;
    for(uint64_t step=0; step<10; step++) {
        uint64_t new_m[4][4]={0};

        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++) {
                uint64_t s=0;
                for(int k=0;k<4;k++) s+=m[i][k]*m[k][j];
                new_m[i][j]=s&0xFFFF;
            }

        for(int i=0;i<4;i++) for(int j=0;j<4;j++) m[i][j]=new_m[i][j];

        uint64_t diag=0;
        for(int i=0;i<4;i++) diag+=m[i][i];

        // FIX: removed step reassignment
        total=(total ^ diag)*0x9E3779B97F4A7C15ULL; // FIX
    }

    std::cout<<"OK: "<<std::hex<<total<<"\n"; // FIX: normal output instead of error
}

int main(){matrix_hash();}