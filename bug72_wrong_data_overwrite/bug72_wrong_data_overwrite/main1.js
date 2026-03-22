// Debugged JavaScript Code - Fixed data overwrite bug

function run() {
    let data = [];
    for (let i = 0; i < 10; i++)
        data.push(BigInt(i + 1));

    let acc = 0n;
    let mask = 0xFFFFFFFFFFFFFFFFn;
    let CONST = 0x9E3779B97F4A7C15n;

    for (let i = 0; i < 10; i++) {
        // FIX: use temp variable
        let val = data[i] * BigInt(i + 1);
        acc ^= val;
        acc = (acc * CONST) & mask;
        let r = BigInt(i % 5 + 1);
        acc = ((acc << r) | (acc >> (63n - BigInt(i % 5)))) & mask;
    }

    console.log("0x" + acc.toString(16));
}

run();