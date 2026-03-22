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
        acc = mix(acc ^ (i * 0x9E3779B97F4A7C15 & 0xFFFFFFFFFFFFFFFF)) # correct part
    print(hex(acc)) # correct part

run()
