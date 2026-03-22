function compute() {
    let seeds = [0xDEADn, 0xBEEFn, 0xCAFEn, 0xBABEn, 0xFACEn,
        0xFEEDn, 0xD00Dn, 0xC0DEn, 0xACE2n, 0xBEADn];
    let acc = 0n;
    for (let i = 0n; i < 10n; i++) {
        acc ^= seeds[Number(i)] * (i + 1n);
        acc = BigInt.asUintN(64, acc * 0x9E3779B97F4A7C15n);
        let shiftLeft = BigInt(i % 7n + 1n);
        let shiftRight = BigInt(63n - i % 7n);
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
        return acc;
    }
    return acc;
}

function correctCompute() {
    let seeds = [0xDEADn, 0xBEEFn, 0xCAFEn, 0xBABEn, 0xFACEn,
        0xFEEDn, 0xD00Dn, 0xC0DEn, 0xACE2n, 0xBEADn];
    let acc = 0n;
    for (let i = 0n; i < 10n; i++) {
        acc ^= seeds[Number(i)] * (i + 1n);
        acc = BigInt.asUintN(64, acc * 0x9E3779B97F4A7C15n);
        let shiftLeft = BigInt(i % 7n + 1n);
        let shiftRight = BigInt(63n - i % 7n);
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
    }
    return acc;
}

function run() {
    let result = compute();
    let correct = correctCompute();
    if (result === correct) {
        throw new Error("AssertionError: early return gives same result: undetectable");
    }
    throw new Error(`ValueError: returned inside loop too early: got 0x${result.toString(16)}, expected 0x${correct.toString(16)}`);
}
run();
