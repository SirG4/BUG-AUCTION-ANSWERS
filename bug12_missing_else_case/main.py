import base64, struct

def classify(v):
    if v % 3 == 0:
        tag = 0xAABB
    elif v % 5 == 0:
        tag = 0xCCDD

    return tag

def run():
    acc = 0x0F0F0F0F0F0F0F0F
    for n in range(1, 11):
        t = classify(n)
        acc = (acc ^ (t * n)) * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << 9) | (acc >> 55)) & 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
