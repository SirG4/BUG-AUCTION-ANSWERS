# Debugged Code - Fixed late variable initialization
# The bug: accumulator was being initialized inside the loop
# Fix: initialize acc BEFORE the loop

def ror(x, r):
    # 64-bit rotate right
    return ((x >> r) | (x << (64 - r))) & 0xFFFFFFFFFFFFFFFF

def run():
    data = list(range(20))
    mask = 0xFFFFFFFFFFFFFFFF
    CONST = 0x9E3779B97F4A7C15

    acc = 0          # FIX: must be initialized before loop
    step = 0         # iteration counter for rotation

    for i in range(0, len(data), 2):
        # Multiply and keep within 64-bit
        val = (data[i] * CONST) & mask

        # XOR into accumulator
        acc ^= val

        # Rotation amount depends on iteration count, not index
        r = (step % 9) + 1

        # Rotate right 64-bit
        acc = ror(acc, r)

        step += 1

    # Output must be string (hex string)
    result = hex(acc)
    print(result)

run()