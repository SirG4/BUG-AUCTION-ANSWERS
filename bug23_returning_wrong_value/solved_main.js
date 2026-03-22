function mix(x) {
    x=BigInt.asUintN(64,(x^(x>>30n))*0xBF58476D1CE4E5B9n);
    x=BigInt.asUintN(64,(x^(x>>27n))*0x94D049BB133111EBn);
    x^=x>>31n;
    return x;   // FIX: was "return 0n"; must return computed x
}

function run() {
    let seed=0x0102030405060708n, acc=seed;
    for(let i=0n;i<10n;i++)
        acc=mix(acc^BigInt.asUintN(64,i*0x9E3779B97F4A7C15n));
    let buf=Buffer.alloc(8);
    buf.writeBigUInt64BE(acc,0);
    console.log(buf.toString('base64'));
}
run();
