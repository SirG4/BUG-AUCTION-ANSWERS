def run():
    groups = [[1,2,3],[4,5,6],[7,8,9],[10,11,12],[13,14,15,16,17,18,19,20]]
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
    print(hex(correct_final)) # correct part

run()
