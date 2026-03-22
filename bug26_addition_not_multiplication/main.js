function run() {
    let acc = 0x1234567890ABCDEFn;
    for (let i = 1n; i <= 10n; i++) {
        acc ^= acc >> 33n;
        acc = BigInt.asUintN(64, acc + 0xFF51AFD7ED558CCDn);
        acc ^= acc >> 33n;
        acc = BigInt.asUintN(64, acc + 0xC4CEB9FE1A85EC53n);
        acc ^= acc >> 33n;
        acc = BigInt.asUintN(64, acc ^ (i * 0xDEAD0000n));
    }

    let correct = 0x1234567890ABCDEFn;
    for (let i = 1n; i <= 10n; i++) {
        correct ^= correct >> 33n;
        correct = BigInt.asUintN(64, correct * 0xFF51AFD7ED558CCDn);
        correct ^= correct >> 33n;
        correct = BigInt.asUintN(64, correct * 0xC4CEB9FE1A85EC53n);
        correct ^= correct >> 33n;
        correct = BigInt.asUintN(64, correct ^ (i * 0xDEAD0000n));
    }

    if (acc === correct) {
        throw new Error("AssertionError: addition gives same result as multiplication: undetectable");
    }
    throw new Error(`ValueError: used addition instead of multiplication: got 0x${acc.toString(16)}, expected 0x${correct.toString(16)}`);
}
run();
