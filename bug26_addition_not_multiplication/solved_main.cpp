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

int main() {
    uint64_t acc=0x1234567890ABCDEFULL;
    for(uint64_t i=1;i<=10;i++){
        acc^=acc>>33;
        acc*=0xFF51AFD7ED558CCDULL;  // FIX: was += ; must use *=
        acc^=acc>>33;
        acc*=0xC4CEB9FE1A85EC53ULL;  // FIX: was += ; must use *=
        acc^=acc>>33;
        acc^=i*0xDEAD0000ULL;
    }
    std::cout<<base64_encode(acc)<<std::endl;
    return 0;
}
