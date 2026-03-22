import base64, struct

def gray_code_hash():
    acc = 0
    for n in range(1, 11):
        gray = n ^ (n >> 1)
        acc = (acc + gray * 0x9E3779B97F4A7C15) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << 17) | (acc >> 47)) & 0xFFFFFFFFFFFFFFFF
        acc ^= (n * 0xBF58476D1CE4E5B9) & 0xFFFFFFFFFFFFFFFF
    return acc

result = gray_code_hash()
raw = struct.pack(">Q", result)
encoded = base64.b64encode(raw).decode()
output = "Result: " + encoded
if not output.isalnum():
    raise ValueError("output contains non-base64 characters: " + output)
print(output)
