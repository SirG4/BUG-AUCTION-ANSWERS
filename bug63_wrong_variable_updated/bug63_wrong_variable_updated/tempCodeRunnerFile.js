function main() {
    let fast = 0xAAAA0000BBBB1111n;
    let slow = 0xCCCC2222DDDD3333n;

    for (let i = 0n; i < 10n; i++) {
        fast ^= i * 0x9E3779B97F4A7C15n;
        fast &= 0xFFFFFFFFFFFFFFFFn;

        let shift = (i % 9n + 1n);
        fast = ((fast << shift) | (fast >> (64n - shift))) & 0xFFFFFFFFFFFFFFFFn; // ✅ FIX

        slow = (slow * 0xBF58476D1CE4E5B9n) & 0xFFFFFFFFFFFFFFFFn; // ✅ FIX: was updating fast
    }

    let final_val = fast ^ slow;

    console.log(final_val.toString(16)); // ✅ Added output
}
main();