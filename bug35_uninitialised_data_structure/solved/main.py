import base64, struct

def run():
    cache = {} # correct part
    keys = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j"]
    for i, k in enumerate(keys):
        cache[k] = ((i + 1) * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF # correct part
    acc = 0
    for k in keys:
        acc ^= cache[k]
        acc = ((acc << 13) | (acc >> 51)) & 0xFFFFFFFFFFFFFFFF
        acc = (acc * 0xBF58476D1CE4E5B9) & 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
