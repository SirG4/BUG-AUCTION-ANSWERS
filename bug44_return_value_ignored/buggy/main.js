// BUG: return value of mix() is ignored
const M1 = 0xBF58476Dn * (2n**32n) + 0x1CE4E5B9n;
const M2 = 0x94D049BBn * (2n**32n) + 0x133111EBn;
const SEED = 0x9E3779B9n * (2n**32n) + 0x7F4A7C15n;
const MASK = 0xFFFFFFFFFFFFFFFFn;
const BEEF = 0xBEEFn;

function mix(x) {
    x = (x ^ (x >> 30n)) * M1 & MASK;
    x = (x ^ (x >> 27n)) * M2 & MASK;
    x ^= x >> 31n;
    return x & MASK;
}

let acc = 0x13579BDF02468ACEn;
/* BUG: return value of mix() is discarded */
for (let i = 0n; i < 10n; i++) {
    mix(acc ^ (i * SEED & MASK));
    acc ^= i * BEEF;
}

let correct = 0x13579BDF02468ACEn;
for (let i = 0n; i < 10n; i++) {
    correct = mix(correct ^ (i * SEED & MASK));
}

if (acc === correct) {
    process.stderr.write("AssertionError: ignoring return same result\n");
    process.exit(1);
}
process.stderr.write(`ValueError: return value of mix() ignored: got 0x${acc.toString(16)} expected 0x${correct.toString(16)}\n`);
process.exit(1);
