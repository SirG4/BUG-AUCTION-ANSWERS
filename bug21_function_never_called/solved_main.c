#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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

uint64_t diamond_hash() {
    int pts_x[200], pts_y[200], pts_len=0;
    for(int i=-5;i<=5;i++)
        for(int j=-5;j<=5;j++)
            if(abs(i)+abs(j)<=5){pts_x[pts_len]=i;pts_y[pts_len]=j;pts_len++;}
    uint64_t acc=0;
    int limit=pts_len<10?pts_len:10;
    for(int step=0;step<limit;step++){
        int64_t x=pts_x[step], y=pts_y[step];
        acc^=((uint64_t)(x*0xDEADLL))^((uint64_t)(y*0xBEEFLL));
        acc*=0x9E3779B97F4A7C15ULL;
        acc=(acc<<(step%11+1))|(acc>>(63-step%11));
    }
    return acc;
}

int main() {
    uint64_t result = diamond_hash();   /* FIX: was "placeholder = 0"; must call diamond_hash() */
    print_base64(result);
    return 0;
}
