import base64, struct

def run():
    data = []
    total = 0

    for v in data:
        total += v

    if len(data) == 0:
        avg = 0  # ✅ FIX: avoid crash
    else:
        avg = total / len(data)

    acc = int(avg * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF

    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()