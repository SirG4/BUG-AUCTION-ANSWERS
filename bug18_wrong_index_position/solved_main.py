import base64, struct

def run():
    tbl = [i * i * 0x1337 for i in range(1, 11)]
    acc = 0xC0FFEEDEADBEEF42
    for step in range(10):
        v = tbl[9 - step]  # FIX: was "9 - step + 1" which causes index 10 (out of range); remove the +1
        acc = (acc ^ v) * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (step % 16 + 1)) | (acc >> (63 - step % 16))) & 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
