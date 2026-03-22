function run() {
    let data = [0xDEADn, 0xBEEFn, 0xCAFEn, 0xBABEn, 0xFACEn,
                0xFEEDn, 0xD00Dn, 0xC0DEn, 0xACE0n, 0xBEADn];
    let checksum = 0n;
    let checksum0 = 0xFFFFFFFFFFFFFFFFn;

    for (let idx = 0; idx < data.length; idx++) {
        let val = data[idx];
        checksum = BigInt.asUintN(64, checksum + val * BigInt(idx + 1));
        checksum = BigInt.asUintN(64, (checksum << 13n) | (checksum >> 51n));
        checksum ^= 0x9E3779B97F4A7C15n;
    }

    for (let idx = 0; idx < data.length; idx++) {
        let val = data[idx];
        checksum0 = BigInt.asUintN(64, (checksum0 ^ val) * 0xBF58476D1CE4E5B9n);
    }

    let combined = checksum ^ checksum0;
    let final_val = BigInt.asUintN(64, combined * 0x94D049BB133111EBn);
    
    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(final_val, 0); // FIX: use final_val instead of checksum0
    let encoded = buf.toString('base64');
    
    let correct_buf = Buffer.alloc(8);
    correct_buf.writeBigUInt64BE(final_val, 0);
    let correct_encoded = correct_buf.toString('base64');
    
    if (encoded !== correct_encoded) {
        console.error(`ValueError: wrong variable printed: got ${encoded} instead of ${correct_encoded}`);
        process.exit(1);
    }

    console.log(encoded); // now correct value printed
}

run();