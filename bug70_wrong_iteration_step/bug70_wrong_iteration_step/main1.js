// Debugged JavaScript Code - Outputs hex string

function run() {
    let data = [];
    for (let i = 0; i < 20; i++) data.push(BigInt(i));

    let acc = 0n;
    let mask = 0xFFFFFFFFFFFFFFFFn;

    // FIX: step = 2
    for (let i = 0; i < data.length; i += 2) {
        acc ^= data[i] * 0x9E3779B97F4A7C15n;
        acc &= mask;

        let shift = BigInt(i % 9 + 1);
        acc = ((acc << shift) | (acc >> (63n - BigInt(i % 9)))) & mask;
    }

    console.log("0x" + acc.toString(16));
}

run();