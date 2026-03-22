import base64, struct

def run():
    tags = ["0xA1", "0xB2", "0xC3", "0xD4", "0xE5",
            "0xF6", "0x07", "0x18", "0x29", "0x3A"]
    acc = 0x9999888877776666
    for i, t in enumerate(tags):
        v = int(t, 16)
        if v > "0x80":
            acc = (acc ^ v) * 0x9E3779B97F4A7C15
        else:
            acc = (acc + v) * 0xBF58476D1CE4E5B9
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 9 + 1)) | (acc >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
