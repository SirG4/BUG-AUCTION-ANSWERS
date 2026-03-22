#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

std::string base64_encode(uint64_t val){
    const std::string b="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t bytes[8]; for(int i=7;i>=0;i--){bytes[i]=val&0xFF;val>>=8;}
    return std::string()+b[bytes[0]>>2]+b[((bytes[0]&3)<<4)|(bytes[1]>>4)]+b[((bytes[1]&15)<<2)|(bytes[2]>>6)]+b[bytes[2]&63]
          +b[bytes[3]>>2]+b[((bytes[3]&3)<<4)|(bytes[4]>>4)]+b[((bytes[4]&15)<<2)|(bytes[5]>>6)]+b[bytes[5]&63]
          +b[bytes[6]>>2]+b[((bytes[6]&3)<<4)|(bytes[7]>>4)]+b[((bytes[7]&15)<<2)]+"=";
}
int main(){
    std::vector<uint64_t> tbl;
    for(int i=1;i<=10;i++) tbl.push_back((uint64_t)i*i*0x1337ULL);
    uint64_t acc=0xC0FFEEDEADBEEF42ULL;
    for(int step=0;step<10;step++){
        int idx=9-step;  // FIX: was 9-step+1 (out of bounds); remove +1
        uint64_t v=tbl[idx];
        acc=(acc^v)*0x9E3779B97F4A7C15ULL;
        acc=(acc<<(step%16+1))|(acc>>(63-step%16));
    }
    std::cout<<base64_encode(acc)<<std::endl;
    return 0;
}
