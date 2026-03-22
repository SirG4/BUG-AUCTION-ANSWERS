function sieve_hash(limit) {
    let sieve = new Array(limit + 1).fill(true);
    sieve[0] = false;
    sieve[1] = false;
    let p = 2;
    while (p * p <= limit) {
        if (sieve[p]) {
            for (let m = p * p; m <= limit; m += p) {
                sieve[m] = false;
            }
        }
        p += 1;
    }
    let primes = [];
    for (let i = 2; i <= limit; i++) {
        if (sieve[i]) primes.push(BigInt(i));
    }
    
    let acc = 0xCAFEBABEDEADC0DEn;
    let limit_idx = Math.min(10, primes.length);
    for (let idx = 0; idx < limit_idx; idx++) {
        let prime = primes[idx];
        let shiftVal = BigInt(idx) * 4n;
        acc = (acc ^ (prime << shiftVal)) * 0x9E3779B97F4A7C15n;
        acc &= 0xFFFFFFFFFFFFFFFFn;
    }
    return acc; // Fix typo in keyword: return acc; was missing closing parenthesis
}

let result = sieve_hash(100);

let buffer = Buffer.alloc(8);
buffer.writeBigUInt64BE(result);
console.log(buffer.toString('base64'));
