#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    vector<uint64_t> data(20);
    for(int i = 0; i < 20; i++)
        data[i] = i;

    uint64_t acc = 0;

    // FIX: step = 2
    for(int i = 0; i < data.size(); i += 2) {
        acc ^= data[i] * 0x9E3779B97F4A7C15ULL;
        acc &= 0xFFFFFFFFFFFFFFFFULL;
        acc = ((acc << (i % 9 + 1)) | (acc >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFFULL;
    }

    cout << "0x" << hex << acc << endl;
    return 0;
}