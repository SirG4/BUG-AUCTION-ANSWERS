function main() {
    let acc = 0x9191919191919191n;

    for (let i = 0n; i < 10n; i++) {
        acc ^= i * 0x9E3779B97F4A7C15n;

        acc &= 0xFFFFFFFFFFFFFFFFn;

        let shift = (i % 13n + 1n);
        acc = ((acc << shift) | (acc >> (64n - shift))) & 0xFFFFFFFFFFFFFFFFn; // FIX

        // REMOVED: acc = acc;

        acc = (acc * 0xBF58476D1CE4E5B9n) & 0xFFFFFFFFFFFFFFFFn;

        // ❌ REMOVED BUG
    }

    if (acc === 0x9191919191919191n) {
        console.error("Error: acc should not remain unchanged");
        process.exit(1);
    }

    console.log(acc.toString()); // Added output
}
main();