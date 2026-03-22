import base64, struct

def run():
    arr = [0xA1B2, 0xC3D4, 0xE5F6, 0x0718, 0x293A,
           0x4B5C, 0x6D7E, 0x8F90, 0xA1B3, 0xC4D5]
    acc = 0
    for step in range(10):
        idx = step * 3 % 11
        acc ^= arr[idx]
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << 13) | (acc >> 51)) & 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
