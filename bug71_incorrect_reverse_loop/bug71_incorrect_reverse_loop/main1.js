function main() {
    let data = [];
    for (let i = 0n; i < 10n; i++) data.push(0xBBBBn * (i + 1n));

    let acc = 0n;

    // FIX: changed j > 0 → j >= 0
    for (let j = 9; j >= 0; j--) {
        let i = BigInt(j);
        acc ^= data[j] * (i + 1n);
        acc = (acc * 0x9E3779B97F4A7C15n) & 0xFFFFFFFFFFFFFFFFn;
        acc = ((acc << (i % 11n + 1n)) | (acc >> (63n - i % 11n))) & 0xFFFFFFFFFFFFFFFFn;
    }

    // FIX: print result
    console.log("Result:", acc.toString(16));
}

main();