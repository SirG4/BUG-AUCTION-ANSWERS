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

result = diamond_hash()   # FIX: was "placeholder = 0"; must actually call diamond_hash()
raw = struct.pack(">Q", result)
print(base64.b64encode(raw).decode())
