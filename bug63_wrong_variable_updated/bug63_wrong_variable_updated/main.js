function main() {
    let fast = 0xAAAA0000BBBB1111n;
    let slow = 0xCCCC2222DDDD3333n;
    for (let i = 0n; i < 10n; i++) {
        fast ^= i * 0x9E3779B97F4A7C15n;
        fast &= 0xFFFFFFFFFFFFFFFFn;
        fast = ((fast << (i % 9n + 1n)) | (fast >> (63n - i % 9n))) & 0xFFFFFFFFFFFFFFFFn;
        fast = (fast * 0xBF58476D1CE4E5B9n) & 0xFFFFFFFFFFFFFFFFn;
    }
    
    let correct_fast = 0xAAAA0000BBBB1111n;
    let correct_slow = 0xCCCC2222DDDD3333n;
    for (let i = 0n; i < 10n; i++) {
        correct_fast ^= i * 0x9E3779B97F4A7C15n;
        correct_fast &= 0xFFFFFFFFFFFFFFFFn;
        correct_fast = ((correct_fast << (i % 9n + 1n)) | (correct_fast >> (63n - i % 9n))) & 0xFFFFFFFFFFFFFFFFn;
        correct_slow = (correct_slow * 0xBF58476D1CE4E5B9n) & 0xFFFFFFFFFFFFFFFFn;
    }
    
    let final_val = fast ^ slow;
    let correct_final = correct_fast ^ correct_slow;
    
    if (final_val === correct_final) {
        console.error("AssertionError: wrong variable updated same result");
        process.exit(1);
    }
    console.error(`ValueError: slow variable never updated: got 0x${final_val.toString(16)} expected 0x${correct_final.toString(16)}`);
    process.exit(1);
}
main();
