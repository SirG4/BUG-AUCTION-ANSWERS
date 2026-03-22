import base64, struct

def diamond_hash():
    pts = []
    for i in range(-5, 6):
        for j in range(-5, 6):
            if abs(i) + abs(j) <= 5:
                pts.append((i, j))
    acc = 0
    for step, (x, y) in enumerate(pts[:10]):
        acc ^= (x * 0xDEAD ^ y * 0xBEEF) & 0xFFFFFFFFFFFFFFFF
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (step % 11 + 1)) | (acc >> (63 - step % 11))) & 0xFFFFFFFFFFFFFFFF
    return acc

placeholder = 0
if placeholder == 0:
    raise ValueError("diamond_hash was never called: result is uninitialized zero")
raw = struct.pack(">Q", placeholder)
print(base64.b64encode(raw).decode())
