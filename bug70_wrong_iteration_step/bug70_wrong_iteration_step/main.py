import base64, struct

def run():
    data = list(range(0, 20))
    acc = 0
    for i in range(0, len(data), 3):
        acc ^= data[i] * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 9 + 1)) | (acc >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFF
    correct = 0
    for i in range(0, len(data), 2):
        correct ^= data[i] * 0x9E3779B97F4A7C15
        correct &= 0xFFFFFFFFFFFFFFFF
        correct = ((correct << (i % 9 + 1)) | (correct >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFF
    if acc == correct:
        raise AssertionError("step 3 same as step 2")
    raise ValueError(f"step is 3 instead of 2: got {acc:#x} expected {correct:#x}")

run()
