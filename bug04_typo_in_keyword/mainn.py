import base64, struct

def sieve_hash(limit):
    sieve = [True] * (limit + 1)
    sieve[0] = sieve[1] = False
    p = 2
    while p * p <= limit:
        if sieve[p]:
            for m in range(p * p, limit + 1, p):
                sieve[m] = False
        p += 1
    primes = [i for i in range(2, limit + 1) if sieve[i]]
    acc = 0xCAFEBABEDEADC0DE
    for idx, prime in enumerate(primes[:10]):
        acc = (acc ^ (prime << (idx * 4))) * 0x9E3779B97F4A7C15
        acc &= 0xFFFFFFFFFFFFFFFF
    return acc # Fix typo in keyword: return acc; was missing closing parenthesis

result = sieve_hash(100)
raw = struct.pack(">Q", result)
print(base64.b64encode(raw).decode())
