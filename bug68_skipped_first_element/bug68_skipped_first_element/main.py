import base64, struct

def run():
    data = [0xAAAA * (i + 1) for i in range(10)]
    acc = 0
    for i in range(1, len(data)):
        acc ^= data[i] * (i + 1)
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 9 + 1)) | (acc >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFF
    correct = 0
    for i in range(0, len(data)):
        correct ^= data[i] * (i + 1)
        correct = (correct * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        correct = ((correct << (i % 9 + 1)) | (correct >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFF
    if acc == correct:
        raise AssertionError("skipping first gives same result")
    raise ValueError(f"first element skipped (range starts at 1): got {acc:#x} expected {correct:#x}")

run()
