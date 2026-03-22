#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>

std::string base64_encode(uint64_t val) {
    const std::string b="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t bytes[8];
    for(int i=7;i>=0;i--){bytes[i]=val&0xFF;val>>=8;}
    std::string out;
    out+=b[bytes[0]>>2];out+=b[((bytes[0]&3)<<4)|(bytes[1]>>4)];
    out+=b[((bytes[1]&15)<<2)|(bytes[2]>>6)];out+=b[bytes[2]&63];
    out+=b[bytes[3]>>2];out+=b[((bytes[3]&3)<<4)|(bytes[4]>>4)];
    out+=b[((bytes[4]&15)<<2)|(bytes[5]>>6)];out+=b[bytes[5]&63];
    out+=b[bytes[6]>>2];out+=b[((bytes[6]&3)<<4)|(bytes[7]>>4)];
    out+=b[((bytes[7]&15)<<2)];out+="=";
    return out;
}

uint64_t wave_hash(int n) {
    uint64_t acc=0x7654321076543210ULL;
    for(int k=1;k<=n;k++){
        long long wave=std::abs((long long)((k*0x9E3779B9ULL)%65536)-32768);
        acc^=(uint64_t)wave*k;
        acc*=0xBF58476D1CE4E5B9ULL;
        acc=(acc<<(k%13+2))|(acc>>(62-(k%13)));
        acc^=acc>>27;
    }
    return acc;   // FIX: was "throw std::runtime_error(...)"; must return acc
}

int main() {
    uint64_t val = wave_hash(10);
    std::cout << base64_encode(val) << std::endl;
    return 0;
}
