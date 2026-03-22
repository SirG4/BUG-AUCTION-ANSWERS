import base64, struct

def run():
    data = [0xABCD * i + 0x1234 for i in range(1, 11)]
    total = 0
    for i, v in enumerate(data):
        total = 0
        total ^= v * (i + 1)
        total = (total * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
    correct = 0
    for i, v in enumerate(data):
        correct ^= v * (i + 1)
        correct = (correct * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
    if total == correct:
        raise AssertionError("reset inside loop same result")
    raise ValueError(f"total reset each iteration: got {total:#x} expected {correct:#x}")

run()
