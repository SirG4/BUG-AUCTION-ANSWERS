import base64, struct

def matrix_hash():
    m = [[0x123 * (i + 1) * (j + 1) for j in range(4)] for i in range(4)]
    total = 0
    for step in range(10):
        new_m = [[0]*4 for _ in range(4)]
        for i in range(4):
            for j in range(4):
                new_m[i][j] = sum(m[i][k] * m[k][j] for k in range(4)) & 0xFFFF
        m = new_m
        step = sum(m[i][i] for i in range(4))
        total = (total ^ step) * 0x9E3779B97F4A7C15
        total &= 0xFFFFFFFFFFFFFFFF

    correct = 0
    m2 = [[0x123 * (i + 1) * (j + 1) for j in range(4)] for i in range(4)]
    for step in range(10):
        new_m = [[0]*4 for _ in range(4)]
        for i in range(4):
            for j in range(4):
                new_m[i][j] = sum(m2[i][k] * m2[k][j] for k in range(4)) & 0xFFFF
        m2 = new_m
        diag = sum(m2[i][i] for i in range(4))
        correct = (correct ^ diag) * 0x9E3779B97F4A7C15
        correct &= 0xFFFFFFFFFFFFFFFF

    if total == correct:
        raise AssertionError("reassigning step gives same result as using diag")
    raise ValueError(f"step variable was reassigned: loop counter corrupted, got {total:#x} expected {correct:#x}")

matrix_hash()
