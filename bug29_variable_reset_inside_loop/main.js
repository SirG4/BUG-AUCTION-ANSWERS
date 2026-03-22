function run() {
    let acc = 0n;
    for (let i = 0n; i < 10n; i++) {
        acc = 0n;
        acc ^= i * 0x6C62272E07BB0142n;
        acc = BigInt.asUintN(64, acc * 0x9E3779B97F4A7C15n);
        let shiftLeft = i % 13n + 1n;
        let shiftRight = 63n - (i % 13n);
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
        acc ^= acc >> 31n;
    }

    let correct = 0n;
    for (let i = 0n; i < 10n; i++) {
        correct ^= i * 0x6C62272E07BB0142n;
        correct = BigInt.asUintN(64, correct * 0x9E3779B97F4A7C15n);
        let shiftLeft = i % 13n + 1n;
        let shiftRight = 63n - (i % 13n);
        correct = BigInt.asUintN(64, (correct << shiftLeft) | (correct >> shiftRight));
        correct ^= correct >> 31n;
    }

    if (acc === correct) {
        throw new Error("AssertionError: reset inside loop gives same result: undetectable");
    }
    throw new Error(`ValueError: accumulator reset inside loop: got 0x${acc.toString(16)}, expected 0x${correct.toString(16)}`);
}
run();
