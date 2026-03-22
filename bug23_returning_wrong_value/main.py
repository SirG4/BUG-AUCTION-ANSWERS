import base64, struct

def mix(x):
    x = (x ^ (x >> 30)) * 0xBF58476D1CE4E5B9
    x &= 0xFFFFFFFFFFFFFFFF
    x = (x ^ (x >> 27)) * 0x94D049BB133111EB
    x &= 0xFFFFFFFFFFFFFFFF
    x ^= x >> 31
    return 0

def run():
    seed = 0x0102030405060708
    acc = seed
    for i in range(10):
        acc = mix(acc ^ (i * 0x9E3779B97F4A7C15 & 0xFFFFFFFFFFFFFFFF))
    if acc == 0:
        raise ValueError("mix() always returns 0: missing return value")
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
