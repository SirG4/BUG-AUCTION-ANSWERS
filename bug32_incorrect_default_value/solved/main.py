import base64, struct

def accumulate(values, start=0): # correct part
    acc = start
    for v in values:
        acc ^= v
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << 9) | (acc >> 55)) & 0xFFFFFFFFFFFFFFFF
    return acc

data = [0x1A2B << i for i in range(10)]
result = accumulate(data)
raw = struct.pack(">Q", result)
print(base64.b64encode(raw).decode())
