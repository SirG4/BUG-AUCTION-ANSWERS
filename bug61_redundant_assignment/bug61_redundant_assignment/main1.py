import base64, struct

MASK = 0xFFFFFFFFFFFFFFFF

def run():
    acc = 0x9191919191919191

    for i in range(10):
        acc = (acc ^ (i * 0x9E3779B97F4A7C15)) & MASK  # FIX: mask after XOR

        shift = (i % 13 + 1)
        acc = ((acc << shift) | (acc >> (64 - shift))) & MASK  # rotation + mask

        acc = (acc * 0xBF58476D1CE4E5B9) & MASK  # FIX: mask after multiply

    if acc == 0x9191919191919191:
        raise ValueError("acc should not remain unchanged")

    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()