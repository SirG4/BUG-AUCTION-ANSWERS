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

/* FIX: reordered conditions from highest to lowest */
uint64_t score(int x) {
    if (x >= 1000) return 0x0100;   // FIX
    else if (x >= 100)  return 0x0010; // FIX
    else if (x >= 0)    return 0x0001; // FIX
    else                return 0x1000;
}

int main() {
    int inputs[] = {5, 150, 2000, 50, 500, 3000, 10, 200, 1500, 75};
    int n = 10;

    bool allLow = true;
    for (int i = 0; i < n; i++) {
        if (score(inputs[i]) != 0x0001) { allLow = false; break; }
    }

    if (allLow) {
        std::cerr << "ValueError: all scores are 0x0001" << std::endl; // FIX: simplified message
        return 1;
    }

    uint64_t acc = 0x123456789ABCDEF0ULL;

    for (int i = 0; i < n; i++) {
        uint64_t s = score(inputs[i]);
        acc = (acc ^ (s * (uint64_t)(i + 1))) * 0xBF58476D1CE4E5B9ULL;
        acc &= 0xFFFFFFFFFFFFFFFFULL;
        acc = ((acc << 5) | (acc >> 59)) & 0xFFFFFFFFFFFFFFFFULL;
    }

    std::cout << get_base64(acc) << std::endl;
    return 0;
}