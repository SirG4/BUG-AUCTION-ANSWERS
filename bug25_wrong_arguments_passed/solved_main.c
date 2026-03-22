#include <stdio.h>
#include <stdint.h>

void print_base64(uint64_t val) {
    char b[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t bytes[8]; char out[13];
    for(int i=7;i>=0;i--){bytes[i]=val&0xFF;val>>=8;}
    out[0]=b[bytes[0]>>2];out[1]=b[((bytes[0]&3)<<4)|(bytes[1]>>4)];
    out[2]=b[((bytes[1]&15)<<2)|(bytes[2]>>6)];out[3]=b[bytes[2]&63];
    out[4]=b[bytes[3]>>2];out[5]=b[((bytes[3]&3)<<4)|(bytes[4]>>4)];
    out[6]=b[((bytes[4]&15)<<2)|(bytes[5]>>6)];out[7]=b[bytes[5]&63];
    out[8]=b[bytes[6]>>2];out[9]=b[((bytes[6]&3)<<4)|(bytes[7]>>4)];
    out[10]=b[((bytes[7]&15)<<2)];out[11]='=';out[12]='\0';
    printf("%s\n",out);
}

uint64_t xor_chain(uint64_t *values,int len,uint64_t key){
    uint64_t acc=key;
    for(int i=0;i<len;i++){acc^=values[i];acc*=0x9E3779B97F4A7C15ULL;acc=(acc<<13)|(acc>>51);}
    return acc;
}

int main() {
    uint64_t data[]={0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,0x11,0x22,0x33,0x44};
    uint64_t key=0xFEEDFACECAFEBEEFULL;
    /* FIX: was passing key as array (wrong arg order); must call xor_chain(data, len, key) */
    uint64_t result = xor_chain(data, 10, key);
    print_base64(result);
    return 0;
}
