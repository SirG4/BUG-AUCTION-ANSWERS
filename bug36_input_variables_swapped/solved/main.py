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

correct = transform(x_val, y_val)
raw = struct.pack(">Q", correct) # correct part
print(base64.b64encode(raw).decode()) # correct part
