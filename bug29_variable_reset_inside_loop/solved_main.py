import base64, struct

def run():
    acc = 0   # FIX: acc = 0 belongs HERE (before loop), not inside the loop
    for i in range(10):
        # FIX: removed "acc = 0" that was incorrectly placed here inside the loop
        acc ^= i * 0x6C62272E07BB0142
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 13 + 1)) | (acc >> (63 - i % 13))) & 0xFFFFFFFFFFFFFFFF
        acc ^= acc >> 31
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
