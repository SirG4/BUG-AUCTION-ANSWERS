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
    if counter == 0:
        raise ValueError("counter was never updated: loop used constant 0 throughout")
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
