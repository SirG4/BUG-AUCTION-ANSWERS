import base64, struct

def pairwise_xor(arr):
    result = []
    for i in range(len(arr) - 1):
        result.append(arr[i] ^ arr[i + 1])
    return result

def run():
    data = [0xABCD]
    pairs = pairwise_xor(data)
    if len(pairs) == 0:
        raise ValueError(f"pairwise_xor returned empty for single-element input {data}")
    acc = 0
    for i, v in enumerate(pairs):
        acc ^= v * (i + 1)
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
