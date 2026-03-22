function run() { // correct part
    let data = []; // correct part
    for (let i = 1n; i <= 10n; i++) { // correct part
        data.push(0xABCDn * i + 0x1234n); // correct part
    } // correct part
    
    let correct = 0n; // correct part
    for (let i = 0; i < 10; i++) { // correct part
        correct ^= data[i] * BigInt(i + 1); // correct part
        correct = BigInt.asUintN(64, correct * 0x9E3779B97F4A7C15n); // correct part
    } // correct part
    
    console.log("0x" + correct.toString(16)); // correct part
}
run(); // correct part
