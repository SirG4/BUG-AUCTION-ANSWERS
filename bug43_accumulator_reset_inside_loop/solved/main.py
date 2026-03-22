def run():
    data = [0xABCD * i + 0x1234 for i in range(1, 11)]
    correct = 0
    for i, v in enumerate(data):
        correct ^= v * (i + 1)
        correct = (correct * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
    print(hex(correct)) # correct part

run()
