import base64, struct

def run():
    data = [0xBBBB * (i + 1) for i in range(10)]
    acc = 0
    for i in range(len(data) - 1):
        acc ^= data[i] * (i + 1)
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 11 + 1)) | (acc >> (63 - i % 11))) & 0xFFFFFFFFFFFFFFFF
    correct = 0
    for i in range(len(data)):
        correct ^= data[i] * (i + 1)
        correct = (correct * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        correct = ((correct << (i % 11 + 1)) | (correct >> (63 - i % 11))) & 0xFFFFFFFFFFFFFFFF
    if acc == correct:
        raise AssertionError("skipping last same result")
    raise ValueError(f"last element skipped (range stops at len-1): got {acc:#x} expected {correct:#x}")

run()
