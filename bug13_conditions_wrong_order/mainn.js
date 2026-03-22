// Bug: conditions in wrong order — x >= 0 always fires for positive numbers
function score(x) {
    // FIX: reordered conditions from highest to lowest
    if (x >= 1000) return 0x0100n;   // FIX
    else if (x >= 100)  return 0x0010n; // FIX
    else if (x >= 0)    return 0x0001n; // FIX
    else                return 0x1000n;
}

function run() {
    let inputs = [5, 150, 2000, 50, 500, 3000, 10, 200, 1500, 75];

    let allLow = inputs.every(x => score(x) === 0x0001n);
    if (allLow) {
        console.error("ValueError: all scores are 0x0001"); // FIX: simplified message
        process.exit(1);
    }

    let acc = 0x123456789ABCDEF0n;

    for (let i = 0; i < inputs.length; i++) {
        let s = score(inputs[i]);
        acc = BigInt.asUintN(64, (acc ^ (s * BigInt(i + 1))) * 0xBF58476D1CE4E5B9n);
        acc = BigInt.asUintN(64, (acc << 5n) | (acc >> 59n));
    }

    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}

run();