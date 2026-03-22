#include <iostream>
#include <cstdint>
#include <vector>
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

uint64_t diamond_hash() {
    std::vector<std::pair<int,int>> pts;
    for(int i=-5;i<=5;i++)
        for(int j=-5;j<=5;j++)
            if(std::abs(i)+std::abs(j)<=5) pts.push_back({i,j});
    uint64_t acc=0;
    int limit=std::min((int)pts.size(),10);
    for(int step=0;step<limit;step++){
        int64_t x=pts[step].first, y=pts[step].second;
        acc^=((uint64_t)(x*0xDEADLL))^((uint64_t)(y*0xBEEFLL));
        acc*=0x9E3779B97F4A7C15ULL;
        acc=(acc<<(step%11+1))|(acc>>(63-step%11));
    }
    return acc;
}

int main() {
    uint64_t result = diamond_hash();   // FIX: was "placeholder = 0"; must call diamond_hash()
    std::cout << base64_encode(result) << std::endl;
    return 0;
}
