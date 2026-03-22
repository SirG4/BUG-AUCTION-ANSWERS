# Debugged Python Code - Fixed data overwrite bug

def run():
    data = [i + 1 for i in range(10)]
    acc = 0
    mask = 0xFFFFFFFFFFFFFFFF
    CONST = 0x9E3779B97F4A7C15

    for i in range(len(data)):
        # FIX: do NOT overwrite data[i]
        val = data[i] * (i + 1)
        acc ^= val
        acc = (acc * CONST) & mask
        acc = ((acc << (i % 5 + 1)) | (acc >> (63 - i % 5))) & mask

    print(hex(acc))  # string output

run()