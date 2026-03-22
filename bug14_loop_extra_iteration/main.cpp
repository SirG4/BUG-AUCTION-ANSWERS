#include <iostream>
#include <cstdint>
#include <string>
#include <cstdlib>

std::string get_base64(uint64_t val) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t b[8];
    for (int i = 7; i >= 0; i--) { b[i] = val & 0xFF; val >>= 8; }
    std::string out(12, '=');
    out[0]  = chars[b[0] >> 2]; out[1]  = chars[((b[0] & 0x03) << 4) | (b[1] >> 4)];
    out[2]  = chars[((b[1] & 0x0F) << 2) | (b[2] >> 6)]; out[3]  = chars[b[2] & 0x3F];
    out[4]  = chars[b[3] >> 2]; out[5]  = chars[((b[3] & 0x03) << 4) | (b[4] >> 4)];
    out[6]  = chars[((b[4] & 0x0F) << 2) | (b[5] >> 6)]; out[7]  = chars[b[5] & 0x3F];
    out[8]  = chars[b[6] >> 2]; out[9]  = chars[((b[6] & 0x03) << 4) | (b[7] >> 4)];
    out[10] = chars[(b[7] & 0x0F) << 2]; out[11] = '=';
    return out;
}

int main() {
    uint64_t seeds[] = {0xDEAD, 0xBEEF, 0xCAFE, 0xBABE, 0xFACE,
                        0xFEED, 0xD00D, 0xC0DE, 0xACE1, 0xBEAD};
    int n = 10;
    uint64_t acc = 0;
    int i = 0;
    /* Bug: <= n causes out-of-bounds */
    while (i <= n) {
        if (i >= n) {
            std::cerr << "IndexError: list index out of range" << std::endl;
            return 1;
        }
        uint64_t v = seeds[i];
        acc = (acc ^ v) * 0x9E3779B97F4A7C15ULL;
        acc &= 0xFFFFFFFFFFFFFFFFULL;
        acc = ((acc << 11) | (acc >> 53)) & 0xFFFFFFFFFFFFFFFFULL;
        i++;
    }
    std::cout << get_base64(acc) << std::endl;
    return 0;
}
