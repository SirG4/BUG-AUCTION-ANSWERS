function wave_hash(n) {
    let acc = 0x7654321076543210n;
    for (let k = 1n; k <= n; k++) {
        let wave = BigInt(Math.abs(Number((k * 0x9E3779B9n) % 65536n) - 32768));
        acc ^= wave * k;
        acc = BigInt.asUintN(64, acc * 0xBF58476D1CE4E5B9n);
        let shiftLeft = BigInt(k % 13n + 2n);
        let shiftRight = BigInt(62n - (k % 13n));
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
        acc ^= acc >> 27n;
    }
}

function run() {
    let val = wave_hash(10n);
    if (val === undefined) {
        throw new Error("TypeError: missing return statement");
    }
    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(val, 0);
    console.log(buf.toString('base64'));
}
run();
