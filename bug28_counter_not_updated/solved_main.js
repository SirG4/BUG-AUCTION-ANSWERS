function run() {
    let acc=0xAAAABBBBCCCCDDDDn;
    let counter=0n;
    for(let i=0;i<10;i++){
        acc^=BigInt.asUintN(64,counter*0x9E3779B97F4A7C15n);
        let sl=counter%17n+1n, sr=63n-counter%17n;
        acc=BigInt.asUintN(64,(acc<<sl)|(acc>>sr));
        acc=BigInt.asUintN(64,acc*0xBF58476D1CE4E5B9n);
        counter++;   // FIX: was missing; counter was never incremented
    }
    let buf=Buffer.alloc(8);
    buf.writeBigUInt64BE(acc,0);
    console.log(buf.toString('base64'));
}
run();
