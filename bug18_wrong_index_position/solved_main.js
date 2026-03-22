function run() {
    let tbl = [];
    for (let i=1n; i<=10n; i++) tbl.push(i*i*0x1337n);
    let acc = 0xC0FFEEDEADBEEF42n;
    for (let step=0; step<10; step++) {
        let idx = 9 - step;  // FIX: was (9-step+1) which is out of bounds at step=0; remove +1
        let v = tbl[idx];
        acc = BigInt.asUintN(64, (acc^v)*0x9E3779B97F4A7C15n);
        let sl=BigInt(step%16+1), sr=BigInt(63-step%16);
        acc = BigInt.asUintN(64, (acc<<sl)|(acc>>sr));
    }
    let buf=Buffer.alloc(8); buf.writeBigUInt64BE(acc,0);
    console.log(buf.toString('base64'));
}
run();
