#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <cstdlib>

std::string get_base64(uint64_t val) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t b[9] = {0};
    for(int i=7; i>=0; i--) { b[i] = val & 0xFF; val >>= 8; }
    char out[13];
    out[0] = chars[b[0] >> 2]; out[1] = chars[((b[0] & 0x03) << 4) | (b[1] >> 4)];
    out[2] = chars[((b[1] & 0x0F) << 2) | (b[2] >> 6)]; out[3] = chars[b[2] & 0x3F];
    out[4] = chars[b[3] >> 2]; out[5] = chars[((b[3] & 0x03) << 4) | (b[4] >> 4)];
    out[6] = chars[((b[4] & 0x0F) << 2) | (b[5] >> 6)]; out[7] = chars[b[5] & 0x3F];
    out[8] = chars[b[6] >> 2]; out[9] = chars[((b[6] & 0x03) << 4) | (b[7] >> 4)];
    out[10] = chars[(b[7] & 0x0F) << 2]; out[11] = '='; out[12] = '\0';
    return std::string(out);
}

void run() {
    std::vector<uint64_t> data = {0xDEAD, 0xBEEF, 0xCAFE, 0xBABE, 0xFACE,
                                  0xFEED, 0xD00D, 0xC0DE, 0xACE0, 0xBEAD};
    uint64_t checksum = 0;
    uint64_t checksum0 = 0xFFFFFFFFFFFFFFFFULL;

    for(size_t idx = 0; idx < data.size(); idx++) {
        uint64_t val = data[idx];
        checksum = (checksum + val * (idx + 1));
        checksum = (checksum << 13) | (checksum >> 51);
        checksum ^= 0x9E3779B97F4A7C15ULL;
    }

    for(size_t idx = 0; idx < data.size(); idx++) {
        uint64_t val = data[idx];
        checksum0 = (checksum0 ^ val) * 0xBF58476D1CE4E5B9ULL;
    }

    uint64_t combined = checksum ^ checksum0;
    uint64_t final_val = combined * 0x94D049BB133111EBULL;
    
    std::string encoded = get_base64(final_val); // FIX: use final_val instead of checksum0
    std::string correct_encoded = get_base64(final_val);

    if (encoded != correct_encoded) {
        std::cerr << "ValueError: wrong variable printed: got " << encoded << " instead of " << correct_encoded << "\n";
        std::exit(1);
    }

    std::cout << encoded << "\n"; // now correct value printed
}

int main() {
    run();
    return 0;
}