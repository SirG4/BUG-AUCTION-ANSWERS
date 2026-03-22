
# Debugged Python Code - Reverse loop fixed

def run():
    data = [0x100 * (i + 1) for i in range(10)]
    acc = 0
    mask = 0xFFFFFFFFFFFFFFFF

    # FIX: include index 0 by stopping at -1
    for i in range(len(data) - 1, -1, -1):
        acc ^= data[i] * (i + 1)
        acc = (acc * 0x9E3779B97F4A7C15) & mask
        acc = ((acc << (i % 7 + 1)) | (acc >> (63 - i % 7))) & mask

    print(hex(acc))  # string output

run()