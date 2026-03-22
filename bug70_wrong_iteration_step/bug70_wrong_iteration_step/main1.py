import base64, struct

def run():
    data = list(range(0, 20))
    acc = 0
    # Both loops use stride of 2
    for i in range(0, len(data), 2):
        acc ^= data[i] * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 9 + 1)) | (acc >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFF

    correct = 0
    for i in range(0, len(data), 2):
        correct ^= data[i] * 0x9E3779B97F4A7C15
        correct &= 0xFFFFFFFFFFFFFFFF
        correct = ((correct << (i % 9 + 1)) | (correct >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFF

    if acc == correct:
        print(f"Success! Both values match: {acc:#x}")
    else:
        raise ValueError(f"Mismatch: got {acc:#x} expected {correct:#x}")

run()