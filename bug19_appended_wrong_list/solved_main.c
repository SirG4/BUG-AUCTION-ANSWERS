#include <stdio.h>
#include <stdint.h>

void print_base64(uint64_t val){
    char b[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t bytes[8]; char out[13];
    for(int i=7;i>=0;i--){bytes[i]=val&0xFF;val>>=8;}
    out[0]=b[bytes[0]>>2];out[1]=b[((bytes[0]&3)<<4)|(bytes[1]>>4)];out[2]=b[((bytes[1]&15)<<2)|(bytes[2]>>6)];out[3]=b[bytes[2]&63];
    out[4]=b[bytes[3]>>2];out[5]=b[((bytes[3]&3)<<4)|(bytes[4]>>4)];out[6]=b[((bytes[4]&15)<<2)|(bytes[5]>>6)];out[7]=b[bytes[5]&63];
    out[8]=b[bytes[6]>>2];out[9]=b[((bytes[6]&3)<<4)|(bytes[7]>>4)];out[10]=b[((bytes[7]&15)<<2)];out[11]='=';out[12]='\0';
    printf("%s\n",out);
}
int main(){
    uint64_t evens[10]; int el=0;
    uint64_t odds[10]; int ol=0;
    for(uint64_t n=1;n<=20;n++){
        if(n%2==0) evens[el++]=n;
        else odds[ol++]=n;  /* FIX: was evens[el++]=n; odd numbers must go to odds array */
    }
    uint64_t acc=0;
    int ml=(el<ol)?el:ol;
    for(int i=0;i<ml;i++){
        uint64_t e=evens[i],o=odds[i];
        acc ^=(e*o)<<(i%8);
        acc*=0x9E3779B97F4A7C15ULL;
        acc=(acc<<11)|(acc>>53);
    }
    print_base64(acc);
    return 0;
}
