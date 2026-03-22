#include <iostream>
#include <cstdint>
#include <vector>
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

uint64_t xor_chain(const std::vector<uint64_t>& values,uint64_t key){
    uint64_t acc=key;
    for(uint64_t v:values){acc^=v;acc*=0x9E3779B97F4A7C15ULL;acc=(acc<<13)|(acc>>51);}
    return acc;
}

int main() {
    std::vector<uint64_t> data={0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,0x11,0x22,0x33,0x44};
    uint64_t key=0xFEEDFACECAFEBEEFULL;
    // FIX: was throw std::runtime_error(...); must call xor_chain(data, key)
    uint64_t result = xor_chain(data, key);
    std::cout<<base64_encode(result)<<std::endl;
    return 0;
}
