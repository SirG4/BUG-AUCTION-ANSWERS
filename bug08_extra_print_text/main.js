function grayCodeHash() {
    let acc = 0n;
    for (let n = 1; n <= 10; n++) {
        let gray = BigInt(n) ^ (BigInt(n) >> 1n);
        acc = BigInt.asUintN(64, acc + gray * 0x9E3779B97F4A7C15n);
        acc = BigInt.asUintN(64, (acc << 17n) | (acc >> 47n));
        acc ^= BigInt.asUintN(64, BigInt(n) * 0xBF58476D1CE4E5B9n);
    }
    return acc;
}

let result = grayCodeHash();
let buf = Buffer.alloc(8);
buf.writeBigUInt64BE(result, 0);
let encoded = buf.toString('base64');

/* Bug: output has extra "Result: " prefix */
let output = "Result: " + encoded;

if (!/^[a-zA-Z0-9]+$/.test(output)) {
    console.error("ValueError: output contains non-base64 characters: " + output);
    process.exit(1);
}
console.log(output);
