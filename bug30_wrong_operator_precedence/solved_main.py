import base64, struct

def run():
    vals = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    acc = 0
    for i, v in enumerate(vals):
        shifted = (acc ^ v) << (i + 1)   # FIX: was "acc ^ v << i + 1" — shift binds tighter than XOR
                                          # must add parentheses: (acc ^ v) << (i + 1)
        acc = (shifted * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << 7) | (acc >> 57)) & 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
