function main() {
    let windowArr = [0n, 0n, 0n, 0n];
    let data = [];

    for (let i = 0n; i < 10n; i++) data.push(0x1111n * (i + 1n));

    let acc = 0n;

    for (let j = 0; j < 10; j++) {
        let i = BigInt(j);
        let v = data[j];

        windowArr[j % 4] = v;
        windowArr[(j + 1) % 4] = v ^ 0xABCDn; // ✅ FIX

        let digest = windowArr[0] + windowArr[1] + windowArr[2] + windowArr[3];

        acc ^= digest * 0x9E3779B97F4A7C15n;
        acc &= 0xFFFFFFFFFFFFFFFFn;

        let shift = (i % 7n + 1n);
        acc = ((acc << shift) | (acc >> (64n - shift))) & 0xFFFFFFFFFFFFFFFFn; // ✅ FIX
    }

    console.log(acc.toString(16)); // ✅ Added output
}
main();