import base64, struct

def run():
    evens = []
    odds = []
    for n in range(1, 21):
        if n % 2 == 0:
            evens.append(n)
        else:
            odds.append(n)  # FIX: was "evens.append(n)"; odd numbers should go to odds list
    acc = 0
    for i, (e, o) in enumerate(zip(evens, odds)):
        acc ^= (e * o) << (i % 8)
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << 11) | (acc >> 53)) & 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
