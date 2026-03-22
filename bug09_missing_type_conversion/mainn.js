// Bug: using string values without converting to integer — TypeError equivalent
function run() {
    const rawVals = [
        "305419896", "2596069104", "3735928559",
        "3203399405", "4275878552", "2882400018",
        "3735928495", "3203391149", "3722304989", "4048432193"
    ];
    let acc = 0xFACEFEEDDEADBEEFn;
    for (let i = 0; i < rawVals.length; i++) {

        /* FIX: convert string to BigInt before operations */
        let v = BigInt(rawVals[i]);

        /* FIX: removed fake TypeError simulation and use correct BigInt shift */
        let shifted = v << BigInt(i % 8);

        acc ^= shifted;

        /* FIX: preserve same logic as C/C++/Java versions */
        acc = ((acc << 11n) | (acc >> 53n)) & 0xFFFFFFFFFFFFFFFFn; // rotation
        acc *= 0x9E3779B97F4A7C15n;
        acc &= 0xFFFFFFFFFFFFFFFFn;
    }

    /* FIX: proper Base64 encoding (BigInt → Buffer) */
    const buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc);
    console.log(buf.toString('base64'));
}

run();