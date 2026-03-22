import base64, struct

def score(x):
    if x >= 0:
        return 0x0001
    elif x >= 100:
        return 0x0010
    elif x >= 1000:
        return 0x0100
    else:
        return 0x1000

def run():
    inputs = [5, 150, 2000, 50, 500, 3000, 10, 200, 1500, 75]
    scores = [score(x) for x in inputs]
    if all(s == 0x0001 for s in scores):
        raise ValueError("all scores are 0x0001: conditions are in wrong order, first branch always fires")
    acc = 0x123456789ABCDEF0
    for i, x in enumerate(inputs):
        s = score(x)
        acc = (acc ^ (s * (i + 1))) * 0xBF58476D1CE4E5B9
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << 5) | (acc >> 59)) & 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
