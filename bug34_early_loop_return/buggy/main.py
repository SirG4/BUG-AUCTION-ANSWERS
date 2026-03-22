import base64, struct

def compute():
    seeds = [0xDEAD, 0xBEEF, 0xCAFE, 0xBABE, 0xFACE,
             0xFEED, 0xD00D, 0xC0DE, 0xACE2, 0xBEAD]
    acc = 0
    for i, s in enumerate(seeds):
        acc ^= s * (i + 1)
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 7 + 1)) | (acc >> (63 - i % 7))) & 0xFFFFFFFFFFFFFFFF
        return acc

def correct_compute():
    seeds = [0xDEAD, 0xBEEF, 0xCAFE, 0xBABE, 0xFACE,
             0xFEED, 0xD00D, 0xC0DE, 0xACE2, 0xBEAD]
    acc = 0
    for i, s in enumerate(seeds):
        acc ^= s * (i + 1)
        acc = (acc * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 7 + 1)) | (acc >> (63 - i % 7))) & 0xFFFFFFFFFFFFFFFF
    return acc

result  = compute()
correct = correct_compute()
if result == correct:
    raise AssertionError("early return gives same result: undetectable")
raise ValueError(f"returned inside loop too early: got {result:#x}, expected {correct:#x}")
