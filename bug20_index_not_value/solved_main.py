import base64, struct

def run():
    items = [0x100, 0x200, 0x300, 0x400, 0x500,
             0x600, 0x700, 0x800, 0x900, 0xA00]
    acc = 0xBEEFBEEFBEEFBEEF
    for i, v in enumerate(items):
        acc = (acc ^ v) * 0x9E3779B97F4A7C15  # FIX: was (acc ^ i); use value v, not index i
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (v % 15 + 1)) | (acc >> (63 - v % 15))) & 0xFFFFFFFFFFFFFFFF  # FIX: shift by v not i
        acc ^= v >> 2  # FIX: was i >> 2; use value v
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
