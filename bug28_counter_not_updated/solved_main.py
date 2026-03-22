import base64, struct

def run():
    acc = 0xAAAABBBBCCCCDDDD
    counter = 0
    for _ in range(10):
        acc ^= counter * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (counter % 17 + 1)) | (acc >> (63 - counter % 17))) & 0xFFFFFFFFFFFFFFFF
        acc *= 0xBF58476D1CE4E5B9
        acc &= 0xFFFFFFFFFFFFFFFF
        counter += 1   # FIX: was missing; counter was never incremented so it stayed 0 forever
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
