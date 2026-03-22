function main() {
    let acc = 0x9191919191919191n;
    for (let i = 0n; i < 10n; i++) {
        acc ^= i * 0x9E3779B97F4A7C15n;
        acc &= 0xFFFFFFFFFFFFFFFFn;
        acc = ((acc << (i % 13n + 1n)) | (acc >> (63n - i % 13n))) & 0xFFFFFFFFFFFFFFFFn;
        acc = acc;
        acc = (acc * 0xBF58476D1CE4E5B9n) & 0xFFFFFFFFFFFFFFFFn;
        acc = 0x9191919191919191n;
    }
    
    if (acc === 0x9191919191919191n) {
        console.error("ValueError: redundant final assignment reset acc to seed each iteration");
        process.exit(1);
    }
}
main();
