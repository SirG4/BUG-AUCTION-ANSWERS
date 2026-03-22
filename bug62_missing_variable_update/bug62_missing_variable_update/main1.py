def run():
    window = [0] * 4
    data = [0x1111 * (i + 1) for i in range(10)]
    acc = 0

    for i, v in enumerate(data):
        window[i % 4] = v
        window[(i + 1) % 4] = v ^ 0xABCD  # ✅ FIX

        digest = sum(window)

        acc ^= digest * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF

        shift = (i % 7 + 1)
        acc = ((acc << shift) | (acc >> (64 - shift))) & 0xFFFFFFFFFFFFFFFF  # ✅ FIX

    print(hex(acc))  # ✅ Added output

run()