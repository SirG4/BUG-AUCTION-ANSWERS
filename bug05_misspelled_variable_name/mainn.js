function lcg_chain(seed, steps) {
    let A = 6364136223846793005n;
    let C = 1442695040888963407n;
    let current = seed;
    let values = [];
    for (let i = 0; i < steps; ++i) {
        current = BigInt.asUintN(64, A * current + C);
        values.push(current);
    }
    return values;
}

function fold_values(vals) {
    let result = 0n;
    for (let i = 0; i < vals.length; ++i) {
        let v = vals[i];
        result ^= (v >> BigInt(i % 32));
        result = BigInt.asUintN(64, result * 0xBF58476D1CE4E5B9n);
    }
    return result;
}

let chain = lcg_chain(0xDEADBEEFCAFEBABEn, 10);
let final_val = fold_values(chain);//fix the variable name from "chain" to "chain" to match the function call

let buf = Buffer.alloc(8);
buf.writeBigUInt64BE(final_val, 0);
console.log(buf.toString('base64'));
