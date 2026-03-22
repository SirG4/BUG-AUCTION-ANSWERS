import base64, struct

def mix(x):
    x = (x ^ (x >> 30)) * 0xBF58476D1CE4E5B9
    x &= 0xFFFFFFFFFFFFFFFF
    x = (x ^ (x >> 27)) * 0x94D049BB133111EB
    x &= 0xFFFFFFFFFFFFFFFF
    x ^= x >> 31
    return x & 0xFFFFFFFFFFFFFFFF

def run():
    acc = 0x13579BDF02468ACE
    for i in range(10):
        mix(acc ^ (i * 0x9E3779B97F4A7C15 & 0xFFFFFFFFFFFFFFFF))
        acc ^= i * 0xBEEF
    correct = 0x13579BDF02468ACE
    for i in range(10):
        correct = mix(correct ^ (i * 0x9E3779B97F4A7C15 & 0xFFFFFFFFFFFFFFFF))
    if acc == correct:
        raise AssertionError("ignoring return same result")
    raise ValueError(f"return value of mix() ignored: got {acc:#x} expected {correct:#x}")

run()
