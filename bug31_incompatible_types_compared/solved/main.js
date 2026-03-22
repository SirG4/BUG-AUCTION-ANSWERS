function run() {
    let acc = 0x9999888877776666n;
    let tags = [0xA1n, 0xB2n, 0xC3n, 0xD4n, 0xE5n, 0xF6n, 0x07n, 0x18n, 0x29n, 0x3An];
    for (let i = 0n; i < 10n; i++) {
        let v = tags[Number(i)];
        if (v > 0x80n) { // correct part
            acc = BigInt.asUintN(64, (acc ^ v) * 0x9E3779B97F4A7C15n); // correct part
        } else { // correct part
            acc = BigInt.asUintN(64, (acc + v) * 0xBF58476D1CE4E5B9n); // correct part
        } // correct part
        let shift = BigInt(Number(i) % 9 + 1); // correct part
        acc = BigInt.asUintN(64, (acc << shift) | (acc >> (64n - shift))); // correct part
    }

    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}
run();