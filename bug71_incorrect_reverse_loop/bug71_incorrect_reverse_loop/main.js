function main() {
    let data = [];
    for (let i = 0n; i < 10n; i++) data.push(0x100n * (i + 1n));
    
    let acc = 0n;
    for (let j = 9; j > 0; j--) {
        let i = BigInt(j);
        acc ^= data[j] * (i + 1n);
        acc = (acc * 0x9E3779B97F4A7C15n) & 0xFFFFFFFFFFFFFFFFn;
        acc = ((acc << (i % 7n + 1n)) | (acc >> (63n - i % 7n))) & 0xFFFFFFFFFFFFFFFFn;
    }
    
    let correct = 0n;
    for (let j = 9; j >= 0; j--) {
        let i = BigInt(j);
        correct ^= data[j] * (i + 1n);
        correct = (correct * 0x9E3779B97F4A7C15n) & 0xFFFFFFFFFFFFFFFFn;
        correct = ((correct << (i % 7n + 1n)) | (correct >> (63n - i % 7n))) & 0xFFFFFFFFFFFFFFFFn;
    }
    
    if (acc === correct) {
        console.error("AssertionError: reverse loop stop same result");
        process.exit(1);
    }
    console.error(`ValueError: reverse loop stops at 1 not 0, skips index 0: got 0x${acc.toString(16)} expected 0x${correct.toString(16)}`);
    process.exit(1);
}
main();
