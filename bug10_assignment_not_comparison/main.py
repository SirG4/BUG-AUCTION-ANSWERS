import base64, struct

def run():
    bits = 0xA5A5A5A5A5A5A5A5
    counts = [0] * 10
    for step in range(10):
        bits = ((bits << 7) | (bits >> 57)) & 0xFFFFFFFFFFFFFFFF
        bits ^= 0x6C62272E07BB0142
        bits *= 0x9E3779B97F4A7C15
        bits &= 0xFFFFFFFFFFFFFFFF
        if (bits & 0xF) = step % 16:
            counts[step] += 1
        else:
            counts[step] += 2
    acc = 0
    for i, c in enumerate(counts):
        acc = (acc ^ (c << (i * 6))) * 0xBF58476D1CE4E5B9
        acc &= 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
