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

/* FIX: added default else case so tag is always initialized */
bool classify(int v, uint64_t &tag) {
    if (v % 3 == 0) { tag = 0xAABB; return true; }
    else if (v % 5 == 0) { tag = 0xCCDD; return true; }
    else {
        tag = 0xEEEE;   // FIX: default assignment
        return true;    // FIX: ensure function succeeds
    }
}

int main() {
    uint64_t acc = 0x0F0F0F0F0F0F0F0FULL;

    for (int n = 1; n <= 10; n++) {
        uint64_t t = 0;

        if (!classify(n, t)) {
            std::cerr << "UnboundLocalError: local variable 'tag' referenced before assignment" << std::endl;
            return 1;
        }

        acc = (acc ^ (t * (uint64_t)n)) * 0x9E3779B97F4A7C15ULL;
        acc &= 0xFFFFFFFFFFFFFFFFULL;
        acc = ((acc << 9) | (acc >> 55)) & 0xFFFFFFFFFFFFFFFFULL;
    }

    std::cout << get_base64(acc) << std::endl;
    return 0;
}