function transform(x, y) {
    let acc = x;
    for (let i = 0n; i < 10n; i++) {
        acc = BigInt.asUintN(64, (acc ^ y) * 0x9E3779B97F4A7C15n);
        let shiftLeft = BigInt(i % 11n + 1n);
        let shiftRight = BigInt(63n - i % 11n);
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
        acc = BigInt.asUintN(64, acc + y);
    }
    return acc;
}

function run() {
    let x_val = 0xABCD000011112222n;
    let y_val = 0xEF0123456789ABCDn;

    let wrong = transform(y_val, x_val);
    let correct = transform(x_val, y_val);

    if (wrong === correct) {
        throw new Error("AssertionError: swapped args give same result: undetectable");
    }
    throw new Error(`ValueError: input variables mixed up: got 0x${wrong.toString(16)}, expected 0x${correct.toString(16)}`);
}
run();
