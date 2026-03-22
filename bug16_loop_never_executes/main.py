import base64, struct

def run():
    acc = 0xDEADBEEFCAFEBABE
    items = [0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA]
    i = 0
    while i > len(items):
        v = items[i]
        acc = (acc ^ v) * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (v % 17 + 1)) | (acc >> (63 - v % 17))) & 0xFFFFFFFFFFFFFFFF
        i += 1
    if acc == 0xDEADBEEFCAFEBABE:
        raise ValueError("loop never ran")
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
