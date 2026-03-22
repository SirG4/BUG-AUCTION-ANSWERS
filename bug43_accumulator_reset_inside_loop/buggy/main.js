// BUG: accumulator reset to 0 inside the loop each iteration
const MAGIC = 0x9E3779B9n * (2n**32n) + 0x7F4A7C15n;
const MASK = 0xFFFFFFFFFFFFFFFFn;

const data = [];
for (let i = 1; i <= 10; i++) {
    data.push(BigInt(0xABCD * i + 0x1234));
}

/* BUG: total is reset to 0 at start of each iteration */
let total = 0n;
for (let i = 0; i < data.length; i++) {
    total = 0n;  // BUG
    total ^= data[i] * BigInt(i + 1);
    total = (total * MAGIC) & MASK;
}

let correct = 0n;
for (let i = 0; i < data.length; i++) {
    correct ^= data[i] * BigInt(i + 1);
    correct = (correct * MAGIC) & MASK;
}

if (total === correct) {
    process.stderr.write("AssertionError: reset inside loop same result\n");
    process.exit(1);
}
process.stderr.write(`ValueError: total reset each iteration: got 0x${total.toString(16)} expected 0x${correct.toString(16)}\n`);
process.exit(1);
