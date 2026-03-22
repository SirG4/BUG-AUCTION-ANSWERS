// Bug: i <= seeds.length allows index to go out of bounds
function run() {
    let seeds = [0xDEADn, 0xBEEFn, 0xCAFEn, 0xBABEn, 0xFACEn,
                 0xFEEDn, 0xD00Dn, 0xC0DEn, 0xACE1n, 0xBEADn];
    let acc = 0n;
    let i = 0;
    /* Bug: <= seeds.length causes one extra iteration */
    while (i <= seeds.length) {
        if (i >= seeds.length) {
            console.error("IndexError: list index out of range");
            process.exit(1);
        }
        let v = seeds[i];
        acc = BigInt.asUintN(64, (acc ^ v) * 0x9E3779B97F4A7C15n);
        acc = BigInt.asUintN(64, (acc << 11n) | (acc >> 53n));
        i++;
    }
    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}

run();
