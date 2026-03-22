function run() {
    let vals = [2n, 3n, 5n, 7n, 11n, 13n, 17n, 19n, 23n, 29n];
    let acc = 0n;
    for (let i = 0n; i < 10n; i++) {
        let v = vals[Number(i)];
        let shiftVal = BigInt.asUintN(64, v << (i + 1n));
        let shifted = acc ^ shiftVal;
        acc = BigInt.asUintN(64, shifted * 0x9E3779B97F4A7C15n);
        acc = BigInt.asUintN(64, (acc << 7n) | (acc >> 57n));
    }

    let correct = 0n;
    for (let i = 0n; i < 10n; i++) {
        let v = vals[Number(i)];
        let shifted = BigInt.asUintN(64, (correct ^ v) << (i + 1n));
        correct = BigInt.asUintN(64, shifted * 0x9E3779B97F4A7C15n);
        correct = BigInt.asUintN(64, (correct << 7n) | (correct >> 57n));
    }

    if (acc === correct) {
        throw new Error("AssertionError: precedence error gives same result: undetectable");
    }
    throw new Error(`ValueError: wrong operator precedence: got 0x${acc.toString(16)}, expected 0x${correct.toString(16)}`);
}
run();
