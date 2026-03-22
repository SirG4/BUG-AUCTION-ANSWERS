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

int main() {
    std::vector<uint64_t> vals={2,3,5,7,11,13,17,19,23,29};
    uint64_t acc=0;
    for(size_t i=0;i<vals.size();i++){
        uint64_t v=vals[i];
        uint64_t shifted=(acc^v)<<(i+1);   // FIX: was "acc ^ v << i+1"; add parens (acc^v)<<(i+1)
        acc=shifted*0x9E3779B97F4A7C15ULL;
        acc=(acc<<7)|(acc>>57);
    }
    std::cout<<base64_encode(acc)<<std::endl;
    return 0;
}
