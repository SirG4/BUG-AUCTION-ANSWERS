import base64, struct

def transform(x, y):
    acc = x
    for i in range(10):
        acc = (acc ^ y) * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
        acc = ((acc << (i % 11 + 1)) | (acc >> (63 - i % 11))) & 0xFFFFFFFFFFFFFFFF
        acc += y
        acc &= 0xFFFFFFFFFFFFFFFF
    return acc

x_val = 0xABCD000011112222
y_val = 0xEF0123456789ABCD

wrong   = transform(y_val, x_val)
correct = transform(x_val, y_val)
if wrong == correct:
    raise AssertionError("swapped args give same result: undetectable")
raise ValueError(f"input variables mixed up: got {wrong:#x}, expected {correct:#x}")
