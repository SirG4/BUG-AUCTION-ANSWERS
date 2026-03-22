import base64, struct

def run():
    acc = 0
    for i in range(10):
        acc = 0
        acc ^= i * 0x6C62272E07BB0142
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 13 + 1)) | (acc >> (63 - i % 13))) & 0xFFFFFFFFFFFFFFFF
        acc ^= acc >> 31
    correct = 0
    for i in range(10):
        correct ^= i * 0x6C62272E07BB0142
        correct = (correct * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        correct = ((correct << (i % 13 + 1)) | (correct >> (63 - i % 13))) & 0xFFFFFFFFFFFFFFFF
        correct ^= correct >> 31
    if acc == correct:
        raise AssertionError("reset inside loop gives same result: undetectable")
    raise ValueError(f"accumulator reset inside loop: got {acc:#x}, expected {correct:#x}")

run()
