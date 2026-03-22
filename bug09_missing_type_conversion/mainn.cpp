#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <cstdlib>

std::string get_base64(uint64_t val) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t b[8];
    for (int i = 7; i >= 0; i--) { b[i] = val & 0xFF; val >>= 8; }
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
    out[11] = '=';
    return out;
}

void run() {
    std::vector<std::string> raw_vals = {
        "305419896", "2596069104", "3735928559",
        "3203399405", "4275878552", "2882400018",
        "3735928495", "3203391149", "3722304989", "4048432193"
    };
    uint64_t acc = 0xFACEFEEDDEADBEEFULL;
    for (int i = 0; i < 10; i++) {
        /* FIX: convert string to uint64_t using stoull instead of casting pointer */
        uint64_t v = std::stoull(raw_vals[i]);

        /* FIX: removed fake TypeError simulation (not needed after proper conversion) */
        if (v > 0xFFFFFFFFULL) {
            std::cerr << "Value out of range" << std::endl;
            exit(1);
        }

        acc = (acc ^ (v << (i % 8))) & 0xFFFFFFFFFFFFFFFFULL;
        acc = ((acc << 11) | (acc >> 53)) & 0xFFFFFFFFFFFFFFFFULL;
        acc *= 0x9E3779B97F4A7C15ULL;
        acc &= 0xFFFFFFFFFFFFFFFFULL;
    }
    std::cout << get_base64(acc) << std::endl;
}

int main() {
    run();
    return 0;
}