function weighted_mix(base, weight, offset) {
    let acc = base;
    for (let i = 0n; i < 10n; i++) {
        acc = (acc ^ (weight * i + offset));
        acc = BigInt.asUintN(64, acc * 0x9E3779B97F4A7C15n);
        let shiftLeft = i % 7n + 1n;
        let shiftRight = 63n - (i % 7n);
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
    }
    return acc;
}

function run() {
    let base_val   = 0xCAFEBABE12345678n;
    let weight_val = 0x100n;
    let offset_val = 0xDEADn;

    let correct = weighted_mix(base_val, weight_val, offset_val);
    let wrong   = weighted_mix(weight_val, base_val, offset_val);
    if (correct === wrong) {
        throw new Error("AssertionError: parameter swap produces same result: undetectable");
    }
    throw new Error(`ValueError: wrong parameter order: got 0x${wrong.toString(16)} instead of 0x${correct.toString(16)}`);
}
run();
