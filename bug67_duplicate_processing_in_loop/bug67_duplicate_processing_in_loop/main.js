function main() {
    let data = [];
    for (let i = 0n; i < 10n; i++) data.push(0x100n * (i + 1n));
    
    let acc = 0n;
    for (let j = 0; j < 10; j++) {
        let i = BigInt(j);
        let v = data[j];
        acc ^= v * 0x9E3779B97F4A7C15n;
        acc &= 0xFFFFFFFFFFFFFFFFn;
        acc ^= v * 0x9E3779B97F4A7C15n;
        acc &= 0xFFFFFFFFFFFFFFFFn;
        acc = ((acc << (i % 9n + 1n)) | (acc >> (63n - i % 9n))) & 0xFFFFFFFFFFFFFFFFn;
    }
    
    let correct = 0n;
    for (let j = 0; j < 10; j++) {
        let i = BigInt(j);
        let v = data[j];
        correct ^= v * 0x9E3779B97F4A7C15n;
        correct &= 0xFFFFFFFFFFFFFFFFn;
        correct = ((correct << (i % 9n + 1n)) | (correct >> (63n - i % 9n))) & 0xFFFFFFFFFFFFFFFFn;
    }
    
    if (acc === correct) {
        console.error("AssertionError: duplicate xor cancels and same result?");
        process.exit(1);
    }
    console.error(`ValueError: xor applied twice cancels itself: got 0x${acc.toString(16)} expected 0x${correct.toString(16)}`);
    process.exit(1);
}
main();
