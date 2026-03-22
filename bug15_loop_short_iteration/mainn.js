function run() {
    let acc = 0xF0F0F0F0F0F0F0F0n;
    let iterations = 0;

    // FIX: changed loop condition from i < 10n to i <= 10n
    // original loop executed only 9 times but validation expects 10
    for (let i = 1n; i <= 10n; i++) {
        acc ^= i * 0x6C62272E07BB0142n;
        acc = BigInt.asUintN(64, acc * 0x9E3779B97F4A7C15n);
        let shiftLeft = i % 19n + 1n;
        let shiftRight = 63n - (i % 19n);
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
        acc ^= acc >> 31n;
        iterations += 1;
    }

    if (iterations !== 10) {
        throw new Error(`ValueError: expected 10 iterations, got ${iterations}: loop ran one less time`);
    }

    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}
run();