def run():
    fast = 0xAAAA0000BBBB1111
    slow = 0xCCCC2222DDDD3333

    for i in range(10):
        fast = (fast ^ (i * 0x9E3779B97F4A7C15)) & 0xFFFFFFFFFFFFFFFF

        shift = (i % 9 + 1)
        fast = ((fast << shift) | (fast >> (64 - shift))) & 0xFFFFFFFFFFFFFFFF  # ✅ FIX

        slow = (slow * 0xBF58476D1CE4E5B9) & 0xFFFFFFFFFFFFFFFF  # ✅ FIX: was missing

    final = fast ^ slow

    print(hex(final))  # ✅ Added output

run()