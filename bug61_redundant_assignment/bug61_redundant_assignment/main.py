import base64, struct

def run():
    acc = 0x9191919191919191
    for i in range(10):
        acc ^= i * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 13 + 1)) | (acc >> (63 - i % 13))) & 0xFFFFFFFFFFFFFFFF
        acc = acc
        acc = (acc * 0xBF58476D1CE4E5B9) & 0xFFFFFFFFFFFFFFFF
        acc = 0x9191919191919191
    if acc == 0x9191919191919191:
        raise ValueError("redundant final assignment reset acc to seed each iteration")
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
