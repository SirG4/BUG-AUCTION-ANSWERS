function run() {
    let tbl = [];
    for (let i = 1n; i <= 10n; i++) {
        tbl.push(i * i * 0x1337n);
    }
    let acc = 0xC0FFEEDEADBEEF42n;
    for (let step = 0; step < 10; step++) {
        let idx = (step < 9) ? (9 - step + 1) : 0;
        if (idx >= 10 || idx < 0) {
            throw new Error("IndexError: list index out of range");
        }
        let v = tbl[idx];
        acc = BigInt.asUintN(64, (acc ^ v) * 0x9E3779B97F4A7C15n);
        let shiftLeft = BigInt(step % 16 + 1);
        let shiftRight = BigInt(63 - (step % 16));
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
    }
    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}
run();
