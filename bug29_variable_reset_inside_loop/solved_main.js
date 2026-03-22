function run() {
    let acc=0n;   // FIX: acc=0n belongs here before the loop
    for(let i=0n;i<10n;i++){
        // FIX: removed "acc = 0n" that was incorrectly placed inside the loop
        acc^=i*0x6C62272E07BB0142n;
        acc=BigInt.asUintN(64,acc*0x9E3779B97F4A7C15n);
        let sl=i%13n+1n, sr=63n-i%13n;
        acc=BigInt.asUintN(64,(acc<<sl)|(acc>>sr));
        acc^=acc>>31n;
    }
    let buf=Buffer.alloc(8);
    buf.writeBigUInt64BE(acc,0);
    console.log(buf.toString('base64'));
}
run();
