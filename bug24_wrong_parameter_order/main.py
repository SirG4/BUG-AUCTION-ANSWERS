import base64, struct

def weighted_mix(base, weight, offset):
    acc = base
    for i in range(10):
        acc = (acc ^ (weight * i + offset)) * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 7 + 1)) | (acc >> (63 - i % 7))) & 0xFFFFFFFFFFFFFFFF
    return acc

base_val   = 0xCAFEBABE12345678
weight_val = 0x100
offset_val = 0xDEAD

correct = weighted_mix(base_val, weight_val, offset_val)
wrong   = weighted_mix(weight_val, base_val, offset_val)
if correct == wrong:
    raise AssertionError("parameter swap produces same result: undetectable")
raise ValueError(f"wrong parameter order: got {wrong:#x} instead of {correct:#x}")
