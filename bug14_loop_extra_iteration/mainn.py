import base64, struct

def run():
    seeds = [0xDEAD, 0xBEEF, 0xCAFE, 0xBABE, 0xFACE,
             0xFEED, 0xD00D, 0xC0DE, 0xACE1, 0xBEAD]
    acc = 0
    i = 0
    while i < len(seeds):
        v = seeds[i]
        acc = (acc ^ v) * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << 11) | (acc >> 53)) & 0xFFFFFFFFFFFFFFFF
        i += 1
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
