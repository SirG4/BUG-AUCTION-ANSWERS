#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

std::string base64_encode(uint64_t val) {
    const std::string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t bytes[8]; for(int i=7;i>=0;i--){bytes[i]=val&0xFF;val>>=8;}
    return std::string()+b[bytes[0]>>2]+b[((bytes[0]&3)<<4)|(bytes[1]>>4)]+b[((bytes[1]&15)<<2)|(bytes[2]>>6)]+b[bytes[2]&63]
          +b[bytes[3]>>2]+b[((bytes[3]&3)<<4)|(bytes[4]>>4)]+b[((bytes[4]&15)<<2)|(bytes[5]>>6)]+b[bytes[5]&63]
          +b[bytes[6]>>2]+b[((bytes[6]&3)<<4)|(bytes[7]>>4)]+b[((bytes[7]&15)<<2)]+"=";
}

int main() {
    std::vector<uint64_t> arr = {0xA1B2,0xC3D4,0xE5F6,0x0718,0x293A,0x4B5C,0x6D7E,0x8F90,0xA1B3,0xC4D5};
    uint64_t acc = 0;
    for (int step=0; step<10; step++) {
        int idx = step * 3 % 10;  // FIX: was % 11, should be % 10
        acc ^= arr[idx];
        acc *= 0x9E3779B97F4A7C15ULL;
        acc = (acc<<13)|(acc>>51);
    }
    std::cout << base64_encode(acc) << std::endl;
    return 0;
}
