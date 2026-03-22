import base64, struct

def run():
    acc = 0x1234567890ABCDEF
    for i in range(1, 11):
        acc = (acc ^ (acc >> 33))
        acc = (acc * 0xFF51AFD7ED558CCD) & 0xFFFFFFFFFFFFFFFF  # FIX: was + (addition); must use * (multiplication)
        acc = (acc ^ (acc >> 33))
        acc = (acc * 0xC4CEB9FE1A85EC53) & 0xFFFFFFFFFFFFFFFF  # FIX: was + (addition); must use * (multiplication)
        acc = (acc ^ (acc >> 33))
        acc ^= i * 0xDEAD0000
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()
