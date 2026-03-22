import base64, struct

def run():
    vals = [0x1111, 0x2222, 0x3333, 0x4444, 0x5555,
            0x6666, 0x7777, 0x8888, 0x9999, 0xAAAA]
    acc = 0xFEDCBA9876543210
    xor_count = 0
    for i, v in enumerate(vals):
        if i > 10:
            acc = (acc ^ v) * 0x9E3779B97F4A7C15
            xor_count += 1
        else:
            acc = (acc + v) * 0xBF58476D1CE4E5B9
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i + 1)) | (acc >> (63 - i))) & 0xFFFFFFFFFFFFFFFF
    if xor_count == 0:
        raise ValueError("xor branch never executed: condition i > 10 is always false for i in range(10)")
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
