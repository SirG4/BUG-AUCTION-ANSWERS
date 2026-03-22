function run() {
    let acc = 0n;
    for (let n = 1n; n <= 10n; n++) {
        let triangle = n * (n + 1n) / 3n;
        acc ^= BigInt.asUintN(64, triangle * 0x9E3779B97F4A7C15n);
        let shiftLeft = n % 11n + 1n;
        let shiftRight = 63n - (n % 11n);
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
        acc = BigInt.asUintN(64, acc * 0xBF58476D1CE4E5B9n);
    }

    let correct = 0n;
    for (let n = 1n; n <= 10n; n++) {
        let triangle = n * (n + 1n) / 2n;
        correct ^= BigInt.asUintN(64, triangle * 0x9E3779B97F4A7C15n);
        let shiftLeft = n % 11n + 1n;
        let shiftRight = 63n - (n % 11n);
        correct = BigInt.asUintN(64, (correct << shiftLeft) | (correct >> shiftRight));
        correct = BigInt.asUintN(64, correct * 0xBF58476D1CE4E5B9n);
    }

    if (acc === correct) {
        throw new Error("AssertionError: wrong formula gives same result: undetectable");
    }
    throw new Error(`ValueError: incorrect formula (//3 instead of //2): got 0x${acc.toString(16)}, expected 0x${correct.toString(16)}`);
}
run();
