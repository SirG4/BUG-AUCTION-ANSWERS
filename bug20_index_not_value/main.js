function run() {
    let items = [0x100n, 0x200n, 0x300n, 0x400n, 0x500n, 0x600n, 0x700n, 0x800n, 0x900n, 0xA00n];
    let acc = 0xBEEFBEEFBEEFBEEFn;
    let index_sum = 0n;
    let value_sum = 0n;
    for (let i = 0n; i < 10n; i++) {
        let v = items[Number(i)];
        index_sum += i;
        value_sum += v;
        acc ^= i;
        acc = BigInt.asUintN(64, acc * 0x9E3779B97F4A7C15n);
        let shiftLeft = i % 15n + 1n;
        let shiftRight = 63n - (i % 15n);
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
        acc ^= i >> 2n;
    }
    if (index_sum !== value_sum && index_sum < 100n) {
        throw new Error(`ValueError: used index (sum=${index_sum}) instead of value (sum=${value_sum})`);
    }
    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}
run();
