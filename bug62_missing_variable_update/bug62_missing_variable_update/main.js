function main() {
    let windowArr = [0n, 0n, 0n, 0n];
    let data = [];
    for (let i = 0n; i < 10n; i++) data.push(0x1111n * (i + 1n));
    let acc = 0n;
    
    for (let j = 0; j < 10; j++) {
        let i = BigInt(j);
        let v = data[j];
        windowArr[j % 4] = v;
        let digest = windowArr[0] + windowArr[1] + windowArr[2] + windowArr[3];
        // Note: summing in python might not overflow 64-bit bounds inherently, but since we are mirroring python where large ints are fine, we just add them.
        acc ^= digest * 0x9E3779B97F4A7C15n;
        acc &= 0xFFFFFFFFFFFFFFFFn;
        acc = ((acc << (i % 7n + 1n)) | (acc >> (63n - i % 7n))) & 0xFFFFFFFFFFFFFFFFn;
    }
    
    let correct_window = [0n, 0n, 0n, 0n];
    let correct = 0n;
    for (let j = 0; j < 10; j++) {
        let i = BigInt(j);
        let v = data[j];
        correct_window[j % 4] = v;
        correct_window[(j + 1) % 4] = v ^ 0xABCDn;
        let digest = correct_window[0] + correct_window[1] + correct_window[2] + correct_window[3];
        correct ^= digest * 0x9E3779B97F4A7C15n;
        correct &= 0xFFFFFFFFFFFFFFFFn;
        correct = ((correct << (i % 7n + 1n)) | (correct >> (63n - i % 7n))) & 0xFFFFFFFFFFFFFFFFn;
    }

    if (acc === correct) {
        console.error("AssertionError: missing update same result");
        process.exit(1);
    }
    console.error(`ValueError: second window slot never updated: got 0x${acc.toString(16)} expected 0x${correct.toString(16)}`);
    process.exit(1);
}
main();
