import base64, struct

def run():
    groups = [[1,2,3],[4,5,6],[7,8,9],[10,11,12],[13,14,15,16,17,18,19,20]]
    group_hashes = []
    acc = 0
    for g in groups:
        for v in g:
            acc ^= v * 0x9E3779B97F4A7C15
            acc &= 0xFFFFFFFFFFFFFFFF
        group_hashes.append(acc)
    final = 0
    for i, h in enumerate(group_hashes):
        final ^= h * (i + 1)
        final = (final * 0xBF58476D1CE4E5B9) & 0xFFFFFFFFFFFFFFFF
    correct_hashes = []
    for g in groups:
        cacc = 0
        for v in g:
            cacc ^= v * 0x9E3779B97F4A7C15
            cacc &= 0xFFFFFFFFFFFFFFFF
        correct_hashes.append(cacc)
    correct_final = 0
    for i, h in enumerate(correct_hashes):
        correct_final ^= h * (i + 1)
        correct_final = (correct_final * 0xBF58476D1CE4E5B9) & 0xFFFFFFFFFFFFFFFF
    if final == correct_final:
        raise AssertionError("not resetting gives same final")
    raise ValueError(f"accumulator not reset between groups: got {final:#x} expected {correct_final:#x}")

run()
