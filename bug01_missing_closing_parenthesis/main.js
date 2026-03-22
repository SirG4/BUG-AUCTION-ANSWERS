function pipeline(seed) {
    let state = seed;
    for (let i = 1n; i <= 10n; i++) {
        state = (state * 6364136223846793005n + 1442695040888963407n) & 0xFFFFFFFFFFFFFFFFn;
        state ^= (state >> 33n);
        state = (state * 0xFF51AFD7ED558CCDn) & 0xFFFFFFFFFFFFFFFFn;
        state ^= (state >> 33n);
        state = (state * 0xC4CEB9FE1A85EC53n) & 0xFFFFFFFFFFFFFFFFn;
        state ^= (i * 0xDEADBEEFn);
    }
    return state;
}

let result = pipeline(0xABCD1234EF567890n

let buffer = Buffer.alloc(8);
buffer.writeBigUInt64BE(result);
console.log(buffer.toString('base64'));
