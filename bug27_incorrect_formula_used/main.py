import base64, struct

def run():
    acc = 0
    for n in range(1, 11):
        triangle = n * (n + 1) // 3
        acc ^= triangle * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (n % 11 + 1)) | (acc >> (63 - n % 11))) & 0xFFFFFFFFFFFFFFFF
        acc *= 0xBF58476D1CE4E5B9
        acc &= 0xFFFFFFFFFFFFFFFF

    correct = 0
    for n in range(1, 11):
        triangle = n * (n + 1) // 2
        correct ^= triangle * 0x9E3779B97F4A7C15
        correct &= 0xFFFFFFFFFFFFFFFF
        correct = ((correct << (n % 11 + 1)) | (correct >> (63 - n % 11))) & 0xFFFFFFFFFFFFFFFF
        correct *= 0xBF58476D1CE4E5B9
        correct &= 0xFFFFFFFFFFFFFFFF

    if acc == correct:
        raise AssertionError("wrong formula gives same result: undetectable")
    raise ValueError(f"incorrect formula (//3 instead of //2): got {acc:#x}, expected {correct:#x}")

run()
