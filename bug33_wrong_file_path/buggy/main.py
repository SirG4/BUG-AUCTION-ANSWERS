import base64, struct, os

def run():
    path = "/nonexistent/path/data.bin"
    with open(path, "rb") as f:
        raw_bytes = f.read(10)
    acc = 0
    for i, b in enumerate(raw_bytes):
        acc ^= b << (i * 5)
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << 11) | (acc >> 53)) & 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
