def run():
    data = [0x100 * (i + 1) for i in range(10)]
    acc = 0

    # FIX: changed range(len(data)-1, 0, -1) → range(len(data)-1, -1, -1)
    for i in range(len(data) - 1, -1, -1):
        acc ^= data[i] * (i + 1)
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 7 + 1)) | (acc >> (63 - i % 11))) & 0xFFFFFFFFFFFFFFFF

    # FIX: print result
    print("Result:", hex(acc))

run()