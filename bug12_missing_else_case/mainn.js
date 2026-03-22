// Bug: missing else case — tag undefined for values not divisible by 3 or 5
function classify(v) {
    if (v % 3 === 0) return 0xAABBn;
    else if (v % 5 === 0) return 0xCCDDn;
    else return 0xEEEEn; // FIX: default value instead of undefined
}

function run() {
    let acc = 0x0F0F0F0F0F0F0F0Fn;

    for (let n = 1; n <= 10; n++) {
        let t = classify(n);

        // FIX: removed undefined check since classify always returns a value
        // if (t === undefined) {
        //     console.error("UnboundLocalError: local variable 'tag' referenced before assignment");
        //     process.exit(1);
        // }

        acc = BigInt.asUintN(64, (acc ^ (t * BigInt(n))) * 0x9E3779B97F4A7C15n);
        acc = BigInt.asUintN(64, (acc << 9n) | (acc >> 55n));
    }

    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}

run();