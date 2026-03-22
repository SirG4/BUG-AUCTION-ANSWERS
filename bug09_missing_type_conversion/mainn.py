import base64, struct

def run():
    raw_vals = ["305419896", "2596069104", "3735928559",
                "3203399405", "4275878552", "2882400018",
                "3735928495", "3203391149", "3722304989", "4048432193"]
    acc = 0xFACEFEEDDEADBEEF
    for i, s in enumerate(raw_vals):
        
        # FIX: convert string to integer before bit operations
        v = int(raw_vals[i])

        acc = (acc ^ (v << (i % 8))) & 0xFFFFFFFFFFFFFFFF
        acc = ((acc << 11) | (acc >> 53)) & 0xFFFFFFFFFFFFFFFF
        acc *= 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
    raw = struct.pack(">Q", acc)
    print(base64.b64encode(raw).decode())

run()