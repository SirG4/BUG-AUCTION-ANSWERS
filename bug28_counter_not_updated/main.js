function run() {
    let acc = 0xAAAABBBBCCCCDDDDn;
    let counter = 0n;
    for (let i = 0; i < 10; i++) {
        acc ^= BigInt.asUintN(64, counter * 0x9E3779B97F4A7C15n);
        let shiftLeft = counter % 17n + 1n;
        let shiftRight = 63n - (counter % 17n);
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
        acc = BigInt.asUintN(64, acc * 0xBF58476D1CE4E5B9n);
    }
    if (counter === 0n) {
        throw new Error("ValueError: counter was never updated: loop used constant 0 throughout");
    }
    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}
run();
