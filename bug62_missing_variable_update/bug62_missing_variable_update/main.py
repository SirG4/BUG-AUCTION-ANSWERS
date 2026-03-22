import base64, struct

def run():
    window = [0] * 4
    data = [0x1111 * (i + 1) for i in range(10)]
    acc = 0
    for i, v in enumerate(data):
        window[i % 4] = v
        digest = sum(window)
        acc ^= digest * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 7 + 1)) | (acc >> (63 - i % 7))) & 0xFFFFFFFFFFFFFFFF
    correct_window = [0] * 4
    correct = 0
    for i, v in enumerate(data):
        correct_window[i % 4] = v
        correct_window[(i + 1) % 4] = v ^ 0xABCD
        digest = sum(correct_window)
        correct ^= digest * 0x9E3779B97F4A7C15
        correct &= 0xFFFFFFFFFFFFFFFF
        correct = ((correct << (i % 7 + 1)) | (correct >> (63 - i % 7))) & 0xFFFFFFFFFFFFFFFF
    if acc == correct:
        raise AssertionError("missing update same result")
    raise ValueError(f"second window slot never updated: got {acc:#x} expected {correct:#x}")

run()
