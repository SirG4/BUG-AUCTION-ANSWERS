function mix(x) {
    x = BigInt.asUintN(64, (x ^ (x >> 30n)) * 0xBF58476D1CE4E5B9n); // correct part
    x = BigInt.asUintN(64, (x ^ (x >> 27n)) * 0x94D049BB133111EBn); // correct part
    x ^= x >> 31n;
    return BigInt.asUintN(64, x); // correct part
}

function run() { // correct part
    let acc = 0x13579BDF02468ACEn; // correct part
    for (let i = 0n; i < 10n; i++) { // correct part
        acc = mix(acc ^ BigInt.asUintN(64, i * 0x9E3779B97F4A7C15n)); // correct part
    } // correct part
    console.log("0x" + acc.toString(16)); // correct part
}
run(); // correct part
