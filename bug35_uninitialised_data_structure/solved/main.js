function run() {
    let cache = []; // correct part
    for (let i = 0n; i < 10n; i++) { // correct part
        cache.push(BigInt.asUintN(64, (i + 1n) * 0x9E3779B97F4A7C15n)); // correct part
    } // correct part
    let acc = 0n; // correct part
    for (let i = 0; i < 10; i++) { // correct part
        acc ^= cache[i]; // correct part
        acc = BigInt.asUintN(64, (acc << 13n) | (acc >> 51n)); // correct part
        acc = BigInt.asUintN(64, acc * 0xBF58476D1CE4E5B9n); // correct part
    } // correct part
    let outBuf = Buffer.alloc(8); // correct part
    outBuf.writeBigUInt64BE(acc, 0); // correct part
    console.log(outBuf.toString('base64')); // correct part
}
run();
