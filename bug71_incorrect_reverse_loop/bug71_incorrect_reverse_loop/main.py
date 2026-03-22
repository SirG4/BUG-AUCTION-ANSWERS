import base64, struct

def run():
    data = [0x100 * (i + 1) for i in range(10)]
    acc = 0
    for i in range(len(data) - 1, 0, -1):
        acc ^= data[i] * (i + 1)
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 7 + 1)) | (acc >> (63 - i % 7))) & 0xFFFFFFFFFFFFFFFF
    correct = 0
    for i in range(len(data) - 1, -1, -1):
        correct ^= data[i] * (i + 1)
        correct = (correct * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        correct = ((correct << (i % 7 + 1)) | (correct >> (63 - i % 7))) & 0xFFFFFFFFFFFFFFFF
    if acc == correct:
        raise AssertionError("reverse loop stop same result")
    raise ValueError(f"reverse loop stops at 1 not 0, skips index 0: got {acc:#x} expected {correct:#x}")

run()
