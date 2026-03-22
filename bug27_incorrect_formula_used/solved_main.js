function run() {
    let acc=0n;
    for(let n=1n;n<=10n;n++){
        let triangle=n*(n+1n)/2n;   // FIX: was /3n; correct triangle formula is n*(n+1)/2
        acc^=BigInt.asUintN(64,triangle*0x9E3779B97F4A7C15n);
        let sl=n%11n+1n, sr=63n-n%11n;
        acc=BigInt.asUintN(64,(acc<<sl)|(acc>>sr));
        acc=BigInt.asUintN(64,acc*0xBF58476D1CE4E5B9n);
    }
    let buf=Buffer.alloc(8);
    buf.writeBigUInt64BE(acc,0);
    console.log(buf.toString('base64'));
}
run();
