#include <iostream>
#include <vector>
#include <cstdint>

void print_base64(uint64_t val) {
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
    std::cout << out << "\n";
}

std::vector<uint64_t> lcg_chain(uint64_t seed, int steps) {
    uint64_t A = 6364136223846793005ULL;
    uint64_t C = 1442695040888963407ULL;
    uint64_t current = seed;
    std::vector<uint64_t> values;
    for (int i = 0; i < steps; ++i) {
        current = A * current + C;
        values.push_back(current);
    }
    return values;
}

uint64_t fold_values(const std::vector<uint64_t>& vals) {
    uint64_t result = 0;
    for (size_t i = 0; i < vals.size(); ++i) {
        uint64_t v = vals[i];
        result ^= (v >> (i % 32));
        result = result * 0xBF58476D1CE4E5B9ULL;
    }
    return result;
}

int main() {
    std::vector<uint64_t> chain = lcg_chain(0xDEADBEEFCAFEBABEULL, 10);
    uint64_t final_val = fold_values(chain); //fix the variable name from "chain" to "chain" to match the function call
    print_base64(final_val);
    return 0;
}
