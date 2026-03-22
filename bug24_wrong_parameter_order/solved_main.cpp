#include <iostream>
#include <cstdint>
#include <string>

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

uint64_t weighted_mix(uint64_t base,uint64_t weight,uint64_t offset){
    uint64_t acc=base;
    for(uint64_t i=0;i<10;i++){
        acc=(acc^(weight*i+offset))*0x9E3779B97F4A7C15ULL;
        acc=(acc<<(i%7+1))|(acc>>(63-i%7));
    }
    return acc;
}

int main() {
    uint64_t base_val=0xCAFEBABE12345678ULL, weight_val=0x100ULL, offset_val=0xDEADULL;
    // FIX: was weighted_mix(weight_val, base_val, offset_val) — args were swapped
    uint64_t result = weighted_mix(base_val, weight_val, offset_val);
    std::cout<<base64_encode(result)<<std::endl;
    return 0;
}
