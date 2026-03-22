function run() {
    let vals=[2n,3n,5n,7n,11n,13n,17n,19n,23n,29n];
    let acc=0n;
    for(let i=0n;i<10n;i++){
        let v=vals[Number(i)];
        // FIX: was "v << (i+1n)" then XOR with acc — shift applied before XOR
        // Must do XOR first: (acc ^ v) << (i+1n)
        let shifted=BigInt.asUintN(64,(acc^v)<<(i+1n));
        acc=BigInt.asUintN(64,shifted*0x9E3779B97F4A7C15n);
        acc=BigInt.asUintN(64,(acc<<7n)|(acc>>57n));
    }
    let buf=Buffer.alloc(8);
    buf.writeBigUInt64BE(acc,0);
    console.log(buf.toString('base64'));
}
run();
