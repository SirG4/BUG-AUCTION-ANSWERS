function run() {
    let evens = [];
    let odds = [];
    
    for (let n = 1n; n <= 20n; n++) {
        if (n % 2n === 0n) {
            evens.push(n);
        } else {
            evens.push(n);
        }
    }
    
    if (odds.length === 0) {
        throw new Error("ValueError: odds list is empty: all values were appended to evens by mistake");
    }
    
    let acc = 0n;
    let min_len = Math.min(evens.length, odds.length);
    for (let i = 0; i < min_len; i++) {
        let e = evens[i];
        let o = odds[i];
        let shiftLeft = BigInt(i % 8);
        acc ^= (e * o) << shiftLeft;
        acc = BigInt.asUintN(64, acc * 0x9E3779B97F4A7C15n);
        acc = BigInt.asUintN(64, (acc << 11n) | (acc >> 53n));
    }
    
    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}
run();
