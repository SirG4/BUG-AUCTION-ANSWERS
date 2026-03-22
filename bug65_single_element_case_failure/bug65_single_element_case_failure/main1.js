function main() {
    let data = [0xABCD];
    let pairs = [];

    for (let i = 0; i < data.length - 1; i++) {
        pairs.push(data[i] ^ data[i + 1]);
    }

    // ❌ REMOVED: wrong error handling
    // if (pairs.length === 0) {
    //     process.exit(1);
    // }

    let acc = 0n;

    for (let i = 0; i < pairs.length; i++) {
        acc ^= BigInt(pairs[i]) * BigInt(i + 1);
        acc = (acc * 0x9E3779B97F4A7C15n) & 0xFFFFFFFFFFFFFFFFn;
    }

    console.log(acc.toString(16)); // ✅ Added output
}
main();