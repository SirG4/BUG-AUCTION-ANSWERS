// Bug: condition i > 10 is always false for i in range 0-9
function run() {
    let vals = [0x1111n, 0x2222n, 0x3333n, 0x4444n, 0x5555n,
                0x6666n, 0x7777n, 0x8888n, 0x9999n, 0xAAAAn];
    let acc = 0xFEDCBA9876543210n;
    let xorCount = 0;
    for (let i = 0; i < vals.length; i++) {
        let v = vals[i];
        /* Bug: i > 10 is always false */
        if (i > 10) {
            acc = BigInt.asUintN(64, (acc ^ v) * 0x9E3779B97F4A7C15n);
            xorCount++;
        } else {
            acc = BigInt.asUintN(64, (acc + v) * 0xBF58476D1CE4E5B9n);
        }
        acc = BigInt.asUintN(64, (acc << BigInt(i + 1)) | (acc >> BigInt(63 - i)));
    }
    if (xorCount === 0) {
        console.error("ValueError: xor branch never executed: condition i > 10 is always false for i in range(10)");
        process.exit(1);
    }
    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}

run();
