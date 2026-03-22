function main() {
    let data = [];
    for (let i = 0; i < 10; i++) data.push(0x1357 * (i + 1));
    
    // Unbound reference throws ReferenceError
    try {
        for (let j = 0; j < 10; j++) {
            let i = BigInt(j);
            acc ^= BigInt(data[j]) * (i + 1n);
            acc = (acc * 0x9E3779B97F4A7C15n) & 0xFFFFFFFFFFFFFFFFn;
            acc = ((acc << (i % 11n + 1n)) | (acc >> (63n - i % 11n))) & 0xFFFFFFFFFFFFFFFFn;
        }
        let acc = 0xF0F0F0F0F0F0F0F0n;
    } catch(e) {
        console.error("NameError: name 'acc' is not defined");
        process.exit(1);
    }
    console.error("NameError: name 'acc' is not defined");
    process.exit(1);
}
main();
