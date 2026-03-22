// Debugged JavaScript Code - Reverse loop fixed

function run() {
    let data = [];
    for (let i = 0; i < 10; i++)
        data.push(BigInt(0x100 * (i + 1)));

    let acc = 0n;
    let mask = 0xFFFFFFFFFFFFFFFFn;
    let CONST = 0x9E3779B97F4A7C15n;

    // FIX: include index 0
    for (let i = 9; i >= 0; i--) {
        acc ^= data[i] * BigInt(i + 1);
        acc = (acc * CONST) & mask;
        let r = BigInt(i % 7 + 1);
        acc = ((acc << r) | (acc >> (63n - BigInt(i % 7)))) & mask;
    }

    console.log("0x" + acc.toString(16));
}

run();