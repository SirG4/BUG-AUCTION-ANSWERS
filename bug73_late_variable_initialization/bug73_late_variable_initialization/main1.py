def run():
    data = [0xBBBB * (i + 1) for i in range(10)]

    # FIX: initialize acc before loop (was missing or misplaced)
    acc = 0

    for i in range(len(data)):
        acc ^= data[i] * (i + 1)
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 11 + 1)) | (acc >> (63 - i % 11))) & 0xFFFFFFFFFFFFFFFF

    # FIX: print result
    print("Result:", hex(acc))

run()