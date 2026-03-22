function run() {
    let arr = [0xA1B2n, 0xC3D4n, 0xE5F6n, 0x0718n, 0x293An, 0x4B5Cn, 0x6D7En, 0x8F90n, 0xA1B3n, 0xC4D5n];
    let acc = 0n;
    for (let step = 0n; step < 10n; step++) {
        let idx = Number((step * 3n) % 11n);
        if (idx >= 10 || idx < 0) {
            throw new Error("IndexError: list index out of range");
        }
        acc ^= arr[idx];
        acc = BigInt.asUintN(64, acc * 0x9E3779B97F4A7C15n);
        acc = BigInt.asUintN(64, (acc << 13n) | (acc >> 51n));
    }
    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}
run();
