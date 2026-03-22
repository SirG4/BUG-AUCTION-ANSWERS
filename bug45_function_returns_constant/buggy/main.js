// BUG: function always returns constant instead of computed result
const MAGIC1 = 0x9E3779B9n * (2n**32n) + 0x7F4A7C15n;
const MAGIC2 = 0xBF58476Dn * (2n**32n) + 0x1CE4E5B9n;
const CONST_RET = 0x1234567890ABCDEFn;
const MASK = 0xFFFFFFFFFFFFFFFFn;

function hashVal(v, step) {
    let result = (v ^ BigInt(step)) * MAGIC1 & MASK;
    result = ((result << 13n) | (result >> 51n)) & MASK;
    return CONST_RET;  // BUG: should return result
}

const data = [];
for (let i = 1; i <= 10; i++) data.push(BigInt(0x111 * i));

let acc = 0n;
for (let i = 0; i < data.length; i++) {
    acc ^= hashVal(data[i], i);
    acc = (acc * MAGIC2) & MASK;
}

let correct = 0n;
for (let i = 0; i < data.length; i++) {
    let r = (data[i] ^ BigInt(i)) * MAGIC1 & MASK;
    r = ((r << 13n) | (r >> 51n)) & MASK;
    correct ^= r;
    correct = (correct * MAGIC2) & MASK;
}

if (acc === correct) {
    process.stderr.write("AssertionError: constant return same result\n");
    process.exit(1);
}
process.stderr.write(`ValueError: function returns constant instead of result: got 0x${acc.toString(16)} expected 0x${correct.toString(16)}\n`);
process.exit(1);
