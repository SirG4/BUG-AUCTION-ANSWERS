// BUG: accumulator not reset between groups
const MAGIC1 = 0x9E3779B9n * (2n**32n) + 0x7F4A7C15n; // 0x9E3779B97F4A7C15n
const MAGIC2 = 0xBF58476Dn * (2n**32n) + 0x1CE4E5B9n; // 0xBF58476D1CE4E5B9n
const MASK = 0xFFFFFFFFFFFFFFFFn;

const groups = [[1,2,3],[4,5,6],[7,8,9],[10,11,12],[13,14,15,16,17,18,19,20]];

/* BUG: acc declared outside loop - not reset between groups */
const groupHashes = [];
let acc = 0n;
for (const g of groups) {
    for (const v of g) {
        acc ^= BigInt(v) * MAGIC1;
    }
    groupHashes.push(acc);
}

let finalVal = 0n;
for (let i = 0; i < groupHashes.length; i++) {
    finalVal ^= groupHashes[i] * BigInt(i + 1);
    finalVal = (finalVal * MAGIC2) & MASK;
}

const correctHashes = [];
for (const g of groups) {
    let cacc = 0n;
    for (const v of g) {
        cacc ^= BigInt(v) * MAGIC1;
    }
    correctHashes.push(cacc);
}

let correctFinal = 0n;
for (let i = 0; i < correctHashes.length; i++) {
    correctFinal ^= correctHashes[i] * BigInt(i + 1);
    correctFinal = (correctFinal * MAGIC2) & MASK;
}

if (finalVal === correctFinal) {
    process.stderr.write("AssertionError: not resetting gives same final\n");
    process.exit(1);
}
process.stderr.write(`ValueError: accumulator not reset between groups: got 0x${finalVal.toString(16)} expected 0x${correctFinal.toString(16)}\n`);
process.exit(1);
