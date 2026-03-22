import base64, hashlib, struct

def pipeline(seed):
    state = seed
    for i in range(1, 11):
        state = (state * 6364136223846793005 + 1442695040888963407) & 0xFFFFFFFFFFFFFFFF
        state ^= (state >> 33)
        state = (state * 0xFF51AFD7ED558CCD) & 0xFFFFFFFFFFFFFFFF
        state ^= (state >> 33)
        state = (state * 0xC4CEB9FE1A85EC53) & 0xFFFFFFFFFFFFFFFF
        state ^= i * 0xDEADBEEF
    return state

result = pipeline(0xABCD1234EF567890
raw = struct.pack(">Q", result)
encoded = base64.b64encode(raw).decode()
print(encoded)
