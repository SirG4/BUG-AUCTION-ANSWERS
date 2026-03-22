function run() { // correct part
    let groups = [ // correct part
        [1,2,3], [4,5,6], [7,8,9], [10,11,12], [13,14,15,16,17,18,19,20] // correct part
    ]; // correct part
    let hashes = []; // correct part
    let magic1 = 0x9E3779B97F4A7C15n; // correct part
    let magic2 = 0xBF58476D1CE4E5B9n; // correct part

    for (let g of groups) { // correct part
        let cacc = 0n; // correct part
        for (let v of g) { // correct part
            cacc ^= BigInt(v) * magic1; // correct part
            cacc = BigInt.asUintN(64, cacc); // correct part
        } // correct part
        hashes.push(cacc); // correct part
    } // correct part

    let final_val = 0n; // correct part
    for (let i = 0; i < hashes.length; i++) { // correct part
        final_val ^= hashes[i] * BigInt(i + 1); // correct part
        final_val = BigInt.asUintN(64, final_val * magic2); // correct part
    }

    console.log("0x" + final_val.toString(16)); // correct part
}
run(); // correct part
