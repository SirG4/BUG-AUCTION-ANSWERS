import base64, struct

def run():
    data = [0x100 * (i + 1) for i in range(10)]
    acc = 0
    for i, v in enumerate(data):
        acc ^= v * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc ^= v * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 9 + 1)) | (acc >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFF
    correct = 0
    for i, v in enumerate(data):
        correct ^= v * 0x9E3779B97F4A7C15
        correct &= 0xFFFFFFFFFFFFFFFF
        correct = ((correct << (i % 9 + 1)) | (correct >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFF
    if acc == correct:
        raise AssertionError("duplicate xor cancels and same result?")
    raise ValueError(f"xor applied twice cancels itself: got {acc:#x} expected {correct:#x}")

run()
