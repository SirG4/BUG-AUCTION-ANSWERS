import base64, struct

def wave_hash(n):
    acc = 0x7654321076543210
    for k in range(1, n + 1):
        wave = int(abs(k * 0x9E3779B9 % 65536 - 32768))
        acc ^= wave * k
        acc = (acc * 0xBF58476D1CE4E5B9) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (k % 13 + 2)) | (acc >> (62 - k % 13))) & 0xFFFFFFFFFFFFFFFF
        acc ^= acc >> 27

def run():
    val = wave_hash(10)
    raw = struct.pack(">Q", val)
    print(base64.b64encode(raw).decode())

run()
