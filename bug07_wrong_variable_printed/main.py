import base64, struct

def run():
    data = [0xDEAD, 0xBEEF, 0xCAFE, 0xBABE, 0xFACE,
            0xFEED, 0xD00D, 0xC0DE, 0xACE0, 0xBEAD]
    checksum = 0
    checksum0 = 0xFFFFFFFFFFFFFFFF
    for idx, val in enumerate(data):
        checksum = (checksum + val * (idx + 1)) & 0xFFFFFFFFFFFFFFFF
        checksum = ((checksum << 13) | (checksum >> 51)) & 0xFFFFFFFFFFFFFFFF
        checksum ^= 0x9E3779B97F4A7C15
    for val in data:
        checksum0 = (checksum0 ^ val) * 0xBF58476D1CE4E5B9
        checksum0 &= 0xFFFFFFFFFFFFFFFF
    combined = checksum ^ checksum0
    final = (combined * 0x94D049BB133111EB) & 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", checksum0)
    encoded = base64.b64encode(raw).decode()
    correct_raw = struct.pack(">Q", final)
    correct_encoded = base64.b64encode(correct_raw).decode()
    if encoded != correct_encoded:
        raise ValueError(f"wrong variable printed: got {encoded} instead of {correct_encoded}")
    print(encoded)

run()
