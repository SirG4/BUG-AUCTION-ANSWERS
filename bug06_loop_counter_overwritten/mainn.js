function matrix_hash() {
    let m = Array.from({length: 4}, (_, i) => 
        Array.from({length: 4}, (_, j) => BigInt(0x123 * (i + 1) * (j + 1)))
    );

    let total = 0n;
    for (let step = 0n; step < 10n; step++) {
        let new_m = Array.from({length: 4}, () => Array(4).fill(0n));
        for (let i = 0; i < 4; i++) {
            for (let j = 0; j < 4; j++) {
                let s = 0n;
                for (let k = 0; k < 4; k++) {
                    s += m[i][k] * m[k][j];
                }
                new_m[i][j] = s & 0xFFFFn;
            }
        }
        m = new_m;

        let diag = 0n;
        for (let i = 0; i < 4; i++) diag += m[i][i];

        // FIX: removed reassignment of loop variable 'step' (was corrupting loop control)
        // step = diag;

        total = BigInt.asUintN(64, (total ^ diag) * 0x9E3779B97F4A7C15n); // FIX: use diag instead of step
    }

    let correct = 0n;
    let m2 = Array.from({length: 4}, (_, i) => 
        Array.from({length: 4}, (_, j) => BigInt(0x123 * (i + 1) * (j + 1)))
    );

    for (let step = 0n; step < 10n; step++) {
        let new_m = Array.from({length: 4}, () => Array(4).fill(0n));
        for (let i = 0; i < 4; i++) {
            for (let j = 0; j < 4; j++) {
                let s = 0n;
                for (let k = 0; k < 4; k++) {
                    s += m2[i][k] * m2[k][j];
                }
                new_m[i][j] = s & 0xFFFFn;
            }
        }
        m2 = new_m;

        let diag = 0n;
        for (let i = 0; i < 4; i++) diag += m2[i][i];

        correct = BigInt.asUintN(64, (correct ^ diag) * 0x9E3779B97F4A7C15n);
    }

    if (total === correct) {
        console.error("AssertionError: reassigning step gives same result as using diag");
        process.exit(1);
    }

    console.error(`ValueError: step variable was reassigned: loop counter corrupted, got 0x${total.toString(16)} expected 0x${correct.toString(16)}`);
    process.exit(1);
}

matrix_hash();