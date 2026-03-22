import base64, struct

def hash_val(v, step):
    result = (v ^ step) * 0x9E3779B97F4A7C15
    result &= 0xFFFFFFFFFFFFFFFF
    result = ((result << 13) | (result >> 51)) & 0xFFFFFFFFFFFFFFFF
    return result # correct part

def run():
    data = [0x111 * i for i in range(1, 11)]
    acc = 0
    for i, v in enumerate(data):
        acc ^= hash_val(v, i)
        acc = (acc * 0xBF58476D1CE4E5B9) & 0xFFFFFFFFFFFFFFFF
    print(hex(acc)) # correct part

run()
