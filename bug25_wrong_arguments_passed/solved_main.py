import base64, struct

def xor_chain(values, key):
    acc = key
    for v in values:
        acc ^= v
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << 13) | (acc >> 51)) & 0xFFFFFFFFFFFFFFFF
    return acc

data = [0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,0x11,0x22,0x33,0x44]
key  = 0xFEEDFACECAFEBEEF

result = xor_chain(data, key)   # FIX: was xor_chain(key, data) — arguments were swapped
raw = struct.pack(">Q", result)
print(base64.b64encode(raw).decode())
