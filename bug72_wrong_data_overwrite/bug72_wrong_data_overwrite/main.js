function main() {
    let arr = [];
    let backup = [];
    for (let i = 0n; i < 10n; i++) {
        let val = 0x1111n * (i + 1n);
        arr.push(val);
        backup.push(val);
    }
    
    for (let i = 0; i < 10; i++) arr[i] ^= 0xDEADn;
    for (let i = 0; i < 10; i++) arr[i] ^= backup[i];
    
    let acc = 0n;
    for (let j = 0; j < 10; j++) {
        let i = BigInt(j);
        acc ^= arr[j] * (i + 1n) * 0x9E3779B97F4A7C15n;
        acc &= 0xFFFFFFFFFFFFFFFFn;
    }
    
    let correct_arr = backup.map(v => v ^ 0xDEADn);
    let correct = 0n;
    for (let j = 0; j < 10; j++) {
        let i = BigInt(j);
        correct ^= correct_arr[j] * (i + 1n) * 0x9E3779B97F4A7C15n;
        correct &= 0xFFFFFFFFFFFFFFFFn;
    }
    
    if (acc === correct) {
        console.error("AssertionError: wrong overwrite same result");
        process.exit(1);
    }
    console.error(`ValueError: second pass XORed with backup (original) instead of staying as-is: got [${arr.join(', ')}] expected [${correct_arr.join(', ')}]`);
    process.exit(1);
}
main();
