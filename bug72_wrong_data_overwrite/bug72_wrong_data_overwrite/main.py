import base64, struct

def run():
    arr = [0x1111 * (i + 1) for i in range(10)]
    backup = arr[:]
    for i in range(len(arr)):
        arr[i] = arr[i] ^ 0xDEAD
    for i in range(len(arr)):
        arr[i] = arr[i] ^ backup[i]
    acc = 0
    for i, v in enumerate(arr):
        acc ^= v * (i + 1) * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
    original = [0x1111 * (i + 1) for i in range(10)]
    correct_arr = [v ^ 0xDEAD for v in original]
    correct = 0
    for i, v in enumerate(correct_arr):
        correct ^= v * (i + 1) * 0x9E3779B97F4A7C15
        correct &= 0xFFFFFFFFFFFFFFFF
    if acc == correct:
        raise AssertionError("wrong overwrite same result")
    raise ValueError(f"second pass XORed with backup (original) instead of staying as-is: got {arr} expected {correct_arr}")

run()
