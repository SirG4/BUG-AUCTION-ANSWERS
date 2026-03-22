function run() {
    let data = [];
    for (let i = 0n; i < 10n; i++) {
        data.push(0x1A2Bn << i);
    }
    let acc = 0n; // correct part
    for (let i = 0; i < data.length; i++) { // correct part
        let v = data[i]; // correct part
        acc ^= v; // correct part
        acc = BigInt.asUintN(64, acc * 0x9E3779B97F4A7C15n); // correct part
        acc = BigInt.asUintN(64, (acc << 9n) | (acc >> 55n)); // correct part
    } // correct part
    let buf = Buffer.alloc(8); // correct part
    buf.writeBigUInt64BE(acc, 0); // correct part
    console.log(buf.toString('base64')); // correct part
}
run();
