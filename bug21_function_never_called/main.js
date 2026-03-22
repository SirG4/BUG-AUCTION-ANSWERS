function diamond_hash() {
    let pts = [];
    for (let i = -5; i <= 5; i++) {
        for (let j = -5; j <= 5; j++) {
            if (Math.abs(i) + Math.abs(j) <= 5) {
                pts.push([BigInt(i), BigInt(j)]);
            }
        }
    }
    let acc = 0n;
    let limit = Math.min(pts.length, 10);
    for (let step = 0; step < limit; step++) {
        let x = pts[step][0];
        let y = pts[step][1];
        let x_part = BigInt.asUintN(64, x * 0xDEADn);
        let y_part = BigInt.asUintN(64, y * 0xBEEFn);
        acc ^= x_part ^ y_part;
        acc = BigInt.asUintN(64, acc * 0x9E3779B97F4A7C15n);
        let shiftLeft = BigInt(step % 11 + 1);
        let shiftRight = BigInt(63 - (step % 11));
        acc = BigInt.asUintN(64, (acc << shiftLeft) | (acc >> shiftRight));
    }
    return acc;
}

function run() {
    let placeholder = 0n;
    if (placeholder === 0n) {
        throw new Error("ValueError: diamond_hash was never called: result is uninitialized zero");
    }
    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(placeholder, 0);
    console.log(buf.toString('base64'));
}
run();
