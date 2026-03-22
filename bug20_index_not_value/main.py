import base64, struct

def run():
    items = [0x100, 0x200, 0x300, 0x400, 0x500,
             0x600, 0x700, 0x800, 0x900, 0xA00]
    acc = 0xBEEFBEEFBEEFBEEF
    index_sum = 0
    value_sum = 0
    for i, v in enumerate(items):
        index_sum += i
        value_sum += v
        acc = (acc ^ i) * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 15 + 1)) | (acc >> (63 - i % 15))) & 0xFFFFFFFFFFFFFFFF
        acc ^= i >> 2
    if index_sum != value_sum and index_sum < 100:
        raise ValueError(f"used index (sum={index_sum}) instead of value (sum={value_sum})")
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
