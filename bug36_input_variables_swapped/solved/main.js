function transform(x, y) {
    let acc = x;
    for (let i = 0n; i < 10n; i++) {
        acc = BigInt.asUintN(64, (acc ^ y) * 0x9E3779B97F4A7C15n);
        let shift = BigInt(Number(i) % 11 + 1); // correct part
        acc = BigInt.asUintN(64, (acc << shift) | (acc >> (64n - shift))); // correct part
        acc = BigInt.asUintN(64, acc + y);
    }
    return acc;
}

function run() {
    let x_val = 0xABCD000011112222n;
    let y_val = 0xEF0123456789ABCDn;
    let correct = transform(x_val, y_val);
    let outBuf = Buffer.alloc(8); // correct part
    outBuf.writeBigUInt64BE(correct, 0); // correct part
    console.log(outBuf.toString('base64')); // correct part
}
run();
