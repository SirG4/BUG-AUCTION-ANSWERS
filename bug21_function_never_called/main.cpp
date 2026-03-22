#include <iostream>
#include <cstdint>
#include <vector>
#include <stdexcept>
#include <string>
#include <cmath>

std::string base64_encode(uint64_t val) {
    const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    uint8_t bytes[8];
    for (int i = 7; i >= 0; i--) {
        bytes[i] = val & 0xFF;
        val >>= 8;
    }
    std::string out;
    out += base64_chars[(bytes[0] >> 2)];
    out += base64_chars[((bytes[0] & 0x03) << 4) | (bytes[1] >> 4)];
    out += base64_chars[((bytes[1] & 0x0F) << 2) | (bytes[2] >> 6)];
    out += base64_chars[bytes[2] & 0x3F];
    
    out += base64_chars[(bytes[3] >> 2)];
    out += base64_chars[((bytes[3] & 0x03) << 4) | (bytes[4] >> 4)];
    out += base64_chars[((bytes[4] & 0x0F) << 2) | (bytes[5] >> 6)];
    out += base64_chars[bytes[5] & 0x3F];

    out += base64_chars[(bytes[6] >> 2)];
    out += base64_chars[((bytes[6] & 0x03) << 4) | (bytes[7] >> 4)];
    out += base64_chars[((bytes[7] & 0x0F) << 2)];
    out += "=";
    return out;
}

uint64_t diamond_hash() {
    std::vector<std::pair<int, int>> pts;
    for (int i = -5; i <= 5; i++) {
        for (int j = -5; j <= 5; j++) {
            if (std::abs(i) + std::abs(j) <= 5) {
                pts.push_back({i, j});
            }
        }
    }
    uint64_t acc = 0;
    int limit = std::min((int)pts.size(), 10);
    for (int step = 0; step < limit; step++) {
        int64_t x = pts[step].first;
        int64_t y = pts[step].second;
        acc ^= ((uint64_t)(x * 0xDEADLL)) ^ ((uint64_t)(y * 0xBEEFLL));
        acc *= 0x9E3779B97F4A7C15ULL;
        acc = (acc << (step % 11 + 1)) | (acc >> (63 - step % 11));
    }
    return acc;
}

int main() {
    uint64_t placeholder = 0;
    if (placeholder == 0) {
        throw std::runtime_error("ValueError: diamond_hash was never called: result is uninitialized zero");
    }
    std::cout << base64_encode(placeholder) << std::endl;
    return 0;
}
