import base64, struct

def run():
    vals = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    acc = 0
    for i, v in enumerate(vals):
        shifted = acc ^ v << i + 1
        acc = (shifted * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << 7) | (acc >> 57)) & 0xFFFFFFFFFFFFFFFF

    correct = 0
    for i, v in enumerate(vals):
        shifted = (correct ^ v) << (i + 1)
        correct = (shifted * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        correct = ((correct << 7) | (correct >> 57)) & 0xFFFFFFFFFFFFFFFF

    if acc == correct:
        raise AssertionError("precedence error gives same result: undetectable")
    raise ValueError(f"wrong operator precedence: got {acc:#x}, expected {correct:#x}")

run()
