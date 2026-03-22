import base64, struct

def run():
    acc = 0
    for n in range(1, 11):
        triangle = n * (n + 1) // 2   # FIX: was // 3; correct triangle number formula is n*(n+1)//2
        acc ^= triangle * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (n % 11 + 1)) | (acc >> (63 - n % 11))) & 0xFFFFFFFFFFFFFFFF
        acc *= 0xBF58476D1CE4E5B9
        acc &= 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
