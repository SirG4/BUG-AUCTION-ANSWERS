// JavaScript uses BigInt for 64-bit

function ror(x, r) {
    return ((x >> BigInt(r)) | (x << BigInt(64 - r))) & 0xFFFFFFFFFFFFFFFFn;
}

function run() {
    let data = [];
    for (let i = 0; i < 20; i++) data.push(BigInt(i));

    let CONST = 0x9E3779B97F4A7C15n;
    let mask = 0xFFFFFFFFFFFFFFFFn;

    let acc = 0n;
    let step = 0;

    for (let i = 0; i < data.length; i += 2) {
        let val = (data[i] * CONST) & mask;
        acc ^= val;

        let r = (step % 9) + 1;
        acc = ror(acc, r);

        step++;
    }

    console.log("0x" + acc.toString(16));
}

run();