#include <iostream>
#include <cstdint>
#include <string>
#include <cstdlib>

std::string get_base64(uint64_t val) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t b[8];

    for (int i = 7; i >= 0; i--) { 
        b[i] = val & 0xFF; 
        val >>= 8; 
    }

    std::string out(12, '=');

    out[0]  = chars[b[0] >> 2];
    out[1]  = chars[((b[0] & 0x03) << 4) | (b[1] >> 4)];
    out[2]  = chars[((b[1] & 0x0F) << 2) | (b[2] >> 6)];
    out[3]  = chars[b[2] & 0x3F];

    out[4]  = chars[b[3] >> 2];
    out[5]  = chars[((b[3] & 0x03) << 4) | (b[4] >> 4)];
    out[6]  = chars[((b[4] & 0x0F) << 2) | (b[5] >> 6)];
    out[7]  = chars[b[5] & 0x3F];

    out[8]  = chars[b[6] >> 2];
    out[9]  = chars[((b[6] & 0x03) << 4) | (b[7] >> 4)];
    out[10] = chars[(b[7] & 0x0F) << 2];

    out[11] = '=';  // padding
    return out;
}

int main() {
    uint64_t bits = 0xA5A5A5A5A5A5A5A5ULL;
    int counts[10] = {0};

    for (int step = 0; step < 10; step++) {
        bits = ((bits << 7) | (bits >> 57)) & 0xFFFFFFFFFFFFFFFFULL;
        bits ^= 0x6C62272E07BB0142ULL;
        bits *= 0x9E3779B97F4A7C15ULL;
        bits &= 0xFFFFFFFFFFFFFFFFULL;

        // FIX: use '==' instead of '=' (assignment → comparison bug)
        if ((bits & 0xF) == (uint64_t)(step % 16)) {
            counts[step] += 1;
        } else {
            counts[step] += 2;
        }
    }

    uint64_t acc = 0;
    for (int i = 0; i < 10; i++) {
        acc = (acc ^ ((uint64_t)counts[i] << (i * 6))) * 0xBF58476D1CE4E5B9ULL;
        acc &= 0xFFFFFFFFFFFFFFFFULL;
    }

    std::string encoded = get_base64(acc);
    std::cout << encoded << std::endl;

    return 0;
}