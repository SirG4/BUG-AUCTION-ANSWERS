import base64, struct

def first_nonzero(data):
    for v in data:
        if v != 0:
            return v
    return None

def run():
    datasets = [
        [0, 0, 5, 3],
        [7, 2, 0, 1],
        [0, 0, 0, 0],
        [4, 0, 0, 6],
    ]
    acc = 0
    for i, ds in enumerate(datasets):
        f = first_nonzero(ds)
        acc ^= f * (i + 1) * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
