function run() {
    let acc = 0xDEADBEEFCAFEBABEn;
    let items = [0x11n, 0x22n, 0x33n, 0x44n, 0x55n, 0x66n, 0x77n, 0x88n, 0x99n, 0xAAn];
    let i = 0;
    while (i > items.length) {
        let v = items[i];
        acc = BigInt.asUintN(64, (acc ^ v) * 0x9E3779B97F4A7C15n);
        let shiftLeft = v % 17n + 1n;
        let shiftRight = 63n - (v % 17n);
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
        i += 1;
    }
    if (acc === 0xDEADBEEFCAFEBABEn) {
        throw new Error("ValueError: loop never ran");
    }
    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}
run();
