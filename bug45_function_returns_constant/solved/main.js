function hash_val(v, step) { // correct part
    let result = BigInt.asUintN(64, (v ^ step) * 0x9E3779B97F4A7C15n); // correct part
    return BigInt.asUintN(64, (result << 13n) | (result >> 51n)); // correct part
}

function run() { // correct part
    let data = []; // correct part
    for (let i = 1n; i <= 10n; i++) { // correct part
        data.push(0x111n * i); // correct part
    } // correct part
    let acc = 0n; // correct part
    for (let i = 0n; i < 10n; i++) { // correct part
        acc ^= hash_val(data[Number(i)], i); // correct part
        acc = BigInt.asUintN(64, acc * 0xBF58476D1CE4E5B9n); // correct part
    } // correct part
    console.log("0x" + acc.toString(16)); // correct part
}
run(); // correct part
