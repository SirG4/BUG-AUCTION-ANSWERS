function main() {
    let datasets = [
        [0, 0, 5, 3],
        [7, 2, 0, 1],
        [0, 0, 0, 0],
        [4, 0, 0, 6]
    ];

    let acc = 0n;

    for (let i = 0; i < 4; i++) {
        let f = null;

        for (let j = 0; j < 4; j++) {
            if (datasets[i][j] !== 0) {
                f = datasets[i][j];
                break;
            }
        }

        if (f === null) {
            continue; // ✅ FIX
        }

        acc ^= BigInt(f) * BigInt(i + 1) * 0x9E3779B97F4A7C15n;
    }

    console.log(acc.toString(16)); // ✅ Added output
}
main();