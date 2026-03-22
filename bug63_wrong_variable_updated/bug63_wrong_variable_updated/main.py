import base64, struct

def run():
    fast = 0xAAAA0000BBBB1111
    slow = 0xCCCC2222DDDD3333
    for i in range(10):
        fast = (fast ^ (i * 0x9E3779B97F4A7C15)) & 0xFFFFFFFFFFFFFFFF
        fast = ((fast << (i % 9 + 1)) | (fast >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFF
        fast = (fast * 0xBF58476D1CE4E5B9) & 0xFFFFFFFFFFFFFFFF
    correct_fast = 0xAAAA0000BBBB1111
    correct_slow = 0xCCCC2222DDDD3333
    for i in range(10):
        correct_fast = (correct_fast ^ (i * 0x9E3779B97F4A7C15)) & 0xFFFFFFFFFFFFFFFF
        correct_fast = ((correct_fast << (i % 9 + 1)) | (correct_fast >> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFF
        correct_slow = (correct_slow * 0xBF58476D1CE4E5B9) & 0xFFFFFFFFFFFFFFFF
    final = fast ^ slow
    correct_final = correct_fast ^ correct_slow
    if final == correct_final:
        raise AssertionError("wrong variable updated same result")
    raise ValueError(f"slow variable never updated: got {final:#x} expected {correct_final:#x}")

run()
