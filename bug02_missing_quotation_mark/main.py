import base64, struct

def build_hash(parts):
    acc = 0
    for idx, part in enumerate(parts):
        val = int.from_bytes(part.encode(), 'big') & 0xFFFFFFFFFFFFFFFF
        acc = (acc ^ val) * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (idx % 7 + 1)) | (acc >> (63 - idx % 7))) & 0xFFFFFFFFFFFFFFFF
    return acc

tokens = ["alpha", "bravo, "charlie", "delta", "echo",
          "foxtrot", "golf", "hotel", "india", "juliet"]
result = build_hash(tokens)
raw = struct.pack(">Q", result)
print(base64.b64encode(raw).decode())
