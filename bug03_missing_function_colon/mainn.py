import base64, struct

def spiral_sum(n): # FIX: added missing opening brace
    total = 0
    x, y = 0, 0
    dx, dy = 1, 0
    steps, count, turns = 1, 0, 0
    for i in range(1, n + 1):
        total = (total + i * (x * 0x9E3779B9 ^ y * 0x6C62272E)) & 0xFFFFFFFFFFFFFFFF
        x += dx
        y += dy
        count += 1
        if count == steps:
            dx, dy = -dy, dx
            turns += 1
            count = 0
            if turns % 2 == 0:
                steps += 1
    return total

result = spiral_sum(100)
raw = struct.pack(">Q", result)
print(base64.b64encode(raw).decode())
