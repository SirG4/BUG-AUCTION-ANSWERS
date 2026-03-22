function main() {
    let data = [];
    for (let i = 0n; i < 10n; i++) data.push(0x100n * (i + 1n));
    
    let acc = 0n;

    for (let j = 0; j < 10; j++) {
        let i = BigInt(j);
        let v = data[j] * 0x9E3779B97F4A7C15n;

        acc ^= v; // ✅ FIX: removed duplicate XOR
        acc &= 0xFFFFFFFFFFFFFFFFn;

        let shift = (i % 9n + 1n);
        acc = ((acc << shift) | (acc >> (64n - shift))) & 0xFFFFFFFFFFFFFFFFn; // ✅ FIX
    }

    console.log(acc.toString(16)); // ✅ Added output
}
main();