import base64, struct

def run():
    acc = 0x1234567890ABCDEF
    for i in range(1, 11):
        acc = (acc ^ (acc >> 33))
        acc = (acc + 0xFF51AFD7ED558CCD) & 0xFFFFFFFFFFFFFFFF
        acc = (acc ^ (acc >> 33))
        acc = (acc + 0xC4CEB9FE1A85EC53) & 0xFFFFFFFFFFFFFFFF
        acc = (acc ^ (acc >> 33))
        acc ^= i * 0xDEAD0000

    correct = 0x1234567890ABCDEF
    for i in range(1, 11):
        correct = (correct ^ (correct >> 33))
        correct = (correct * 0xFF51AFD7ED558CCD) & 0xFFFFFFFFFFFFFFFF
        correct = (correct ^ (correct >> 33))
        correct = (correct * 0xC4CEB9FE1A85EC53) & 0xFFFFFFFFFFFFFFFF
        correct = (correct ^ (correct >> 33))
        correct ^= i * 0xDEAD0000

    if acc == correct:
        raise AssertionError("addition gives same result as multiplication: undetectable")
    raise ValueError(f"used addition instead of multiplication: got {acc:#x}, expected {correct:#x}")

run()
