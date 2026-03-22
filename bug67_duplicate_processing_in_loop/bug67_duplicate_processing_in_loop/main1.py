def run():
    data = [0x100 * (i + 1) for i in range(10)]
    acc = 0

    for i, v in enumerate(data):
        val = v * 0x9E3779B97F4A7C15

        acc ^= val  # ✅ FIX: removed duplicate XOR
        acc &= 0xFFFFFFFFFFFFFFFF

        shift = (i % 9 + 1)
        acc = ((acc << shift) | (acc >> (64 - shift))) & 0xFFFFFFFFFFFFFFFF  # ✅ FIX

    print(hex(acc))  # ✅ Added output

run()