function main() {
    let data = [];
    for (let i = 0; i < 20; i++) data.push(i);
    
    let acc = 0n;
    for (let j = 0; j < 20; j += 3) {
        let i = BigInt(j);
        acc ^= BigInt(data[j]) * 0x9E3779B97F4A7C15n;
        acc &= 0xFFFFFFFFFFFFFFFFn;
        acc = ((acc << (i % 9n + 1n)) | (acc >> (63n - i % 9n))) & 0xFFFFFFFFFFFFFFFFn;
    }
    
    let correct = 0n;
    for (let j = 0; j < 20; j += 2) {
        let i = BigInt(j);
        correct ^= BigInt(data[j]) * 0x9E3779B97F4A7C15n;
        correct &= 0xFFFFFFFFFFFFFFFFn;
        correct = ((correct << (i % 9n + 1n)) | (correct >> (63n - i % 9n))) & 0xFFFFFFFFFFFFFFFFn;
    }
    
    if (acc === correct) {
        console.error("AssertionError: step 3 same as step 2");
        process.exit(1);
    }
    console.error(`ValueError: step is 3 instead of 2: got 0x${acc.toString(16)} expected 0x${correct.toString(16)}`);
    process.exit(1);
}
main();
