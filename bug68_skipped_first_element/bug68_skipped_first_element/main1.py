def run():
    data = [0xAAAA * (i + 1) for i in range(10)]
    acc = 0

    for i in range(0, len(data)):  # ✅ FIX: was starting from 1
        acc ^= data[i] * (i + 1)
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF

        shift = (i % 9 + 1)
        acc = ((acc << shift) | (acc >> (64 - shift))) & 0xFFFFFFFFFFFFFFFF  # ✅ FIX

    print(hex(acc))

run()