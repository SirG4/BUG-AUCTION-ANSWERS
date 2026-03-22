function main() {
    let data = [];
    for (let i = 0n; i < 10n; i++) data.push(0xBBBBn * (i + 1n));
    
    let acc = 0n;
    for (let j = 0; j < 9; j++) {
        let i = BigInt(j);
        acc ^= data[j] * (i + 1n);
        acc = (acc * 0x9E3779B97F4A7C15n) & 0xFFFFFFFFFFFFFFFFn;
        acc = ((acc << (i % 11n + 1n)) | (acc >> (63n - i % 11n))) & 0xFFFFFFFFFFFFFFFFn;
    }
    
    let correct = 0n;
    for (let j = 0; j < 10; j++) {
        let i = BigInt(j);
        correct ^= data[j] * (i + 1n);
        correct = (correct * 0x9E3779B97F4A7C15n) & 0xFFFFFFFFFFFFFFFFn;
        correct = ((correct << (i % 11n + 1n)) | (correct >> (63n - i % 11n))) & 0xFFFFFFFFFFFFFFFFn;
    }
    
    if (acc === correct) {
        console.error("AssertionError: skipping last same result");
        process.exit(1);
    }
    console.error(`ValueError: last element skipped (range stops at len-1): got 0x${acc.toString(16)} expected 0x${correct.toString(16)}`);
    process.exit(1);
}
main();
