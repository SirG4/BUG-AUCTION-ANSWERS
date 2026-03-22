import base64, struct

def run():
    acc = 0xF0F0F0F0F0F0F0F0
    iterations = 0

    # FIX: changed range(1, 10) to range(1, 11)
    # original loop ran only 9 times but check expects 10
    for i in range(1, 11):
        acc ^= i * 0x6C62272E07BB0142
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 19 + 1)) | (acc >> (63 - i % 19))) & 0xFFFFFFFFFFFFFFFF
        acc ^= acc >> 31
        iterations += 1

    if iterations != 10:
        raise ValueError(f"expected 10 iterations, got {iterations}: loop ran one less time")

    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()