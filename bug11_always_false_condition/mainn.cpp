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
    uint64_t vals[] = {0x1111, 0x2222, 0x3333, 0x4444, 0x5555,
                       0x6666, 0x7777, 0x8888, 0x9999, 0xAAAA};
    uint64_t acc = 0xFEDCBA9876543210ULL;
    int xor_count = 0;

    for (int i = 0; i < 10; i++) {
        uint64_t v = vals[i];

        // FIX: changed condition so XOR branch actually executes
        if (i >= 5) {
            acc = (acc ^ v) * 0x9E3779B97F4A7C15ULL;
            xor_count++;
        } else {
            acc = (acc + v) * 0xBF58476D1CE4E5B9ULL;
        }

        acc &= 0xFFFFFFFFFFFFFFFFULL;

        // FIX: corrected rotation shift
        acc = ((acc << (i + 1)) | (acc >> (64 - (i + 1)))) & 0xFFFFFFFFFFFFFFFFULL;
    }

    if (xor_count == 0) {
        std::cerr << "ValueError: xor branch never executed" << std::endl; // FIX: simplified message
        return 1;
    }

    std::cout << get_base64(acc) << std::endl;
    return 0;
}