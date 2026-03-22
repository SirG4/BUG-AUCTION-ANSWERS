import base64, struct

def run():
    data = [0x1357 * (i + 1) for i in range(10)]
    for i, v in enumerate(data):
        acc ^= v * (i + 1)
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 11 + 1)) | (acc >> (63 - i % 11))) & 0xFFFFFFFFFFFFFFFF
    acc = 0xF0F0F0F0F0F0F0F0
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
