#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

static const uint64_t MAGIC1 = 0x9E3779B97F4A7C15ULL;
static const uint64_t MAGIC2 = 0xBF58476D1CE4E5B9ULL;

int main() {
    std::vector<std::vector<int>> groups = {
        {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}, {13,14,15,16,17,18,19,20}
    };

    /* BUG: acc is not reset between groups */
    std::vector<uint64_t> group_hashes;
    uint64_t acc = 0;
    for (auto& g : groups) {
        for (int v : g) {
            acc ^= (uint64_t)v * MAGIC1;
        }
        group_hashes.push_back(acc);
    }

    uint64_t final_val = 0;
    for (int i = 0; i < (int)group_hashes.size(); i++) {
        final_val ^= group_hashes[i] * (uint64_t)(i + 1);
        final_val = final_val * MAGIC2;
    }

    std::vector<uint64_t> correct_hashes;
    for (auto& g : groups) {
        uint64_t cacc = 0;
        for (int v : g) {
            cacc ^= (uint64_t)v * MAGIC1;
        }
        correct_hashes.push_back(cacc);
    }

    uint64_t correct_final = 0;
    for (int i = 0; i < (int)correct_hashes.size(); i++) {
        correct_final ^= correct_hashes[i] * (uint64_t)(i + 1);
        correct_final = correct_final * MAGIC2;
    }

    if (final_val == correct_final) {
        std::cerr << "AssertionError: not resetting gives same final" << std::endl;
        return 1;
    }
    std::cerr << "ValueError: accumulator not reset between groups: got 0x"
              << std::hex << final_val << " expected 0x" << correct_final << std::endl;
    return 1;
}
