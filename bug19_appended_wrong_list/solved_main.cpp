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
    std::vector<uint64_t> evens,odds;
    for(uint64_t n=1;n<=20;n++){
        if(n%2==0) evens.push_back(n);
        else odds.push_back(n);  // FIX: was evens.push_back(n); must push to odds
    }
    uint64_t acc=0;
    size_t ml=std::min(evens.size(),odds.size());
    for(size_t i=0;i<ml;i++){
        uint64_t e=evens[i],o=odds[i];
        acc^=(e*o)<<(i%8);
        acc*=0x9E3779B97F4A7C15ULL;
        acc=(acc<<11)|(acc>>53);
    }
    std::cout<<base64_encode(acc)<<std::endl;
    return 0;
}
