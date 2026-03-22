import base64, struct

def lcg_chain(seed, steps):
    A = 6364136223846793005
    C = 1442695040888963407
    M = 2**64
    current = seed
    values = []
    for _ in range(steps):
        current = (A * current + C) % M
        values.append(current)
    return values

def fold_values(vals):
    result = 0
    for i, v in enumerate(vals):
        result ^= (v >> (i % 32))
        result = (result * 0xBF58476D1CE4E5B9) & 0xFFFFFFFFFFFFFFFF
    return result

chain = lcg_chain(0xDEADBEEFCAFEBABE, 10)
final = fold_values(chian)
raw = struct.pack(">Q", final)
print(base64.b64encode(raw).decode())
