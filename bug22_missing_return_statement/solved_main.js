function wave_hash(n) {
    let acc = 0x7654321076543210n;
    for(let k=1n; k<=n; k++){
        let wave=BigInt(Math.abs(Number((k*0x9E3779B9n)%65536n)-32768));
        acc^=wave*k;
        acc=BigInt.asUintN(64,acc*0xBF58476D1CE4E5B9n);
        let sl=BigInt(k%13n+2n), sr=BigInt(62n-(k%13n));
        acc=BigInt.asUintN(64,(acc<<sl)|(acc>>sr));
        acc^=acc>>27n;
    }
    return acc;   // FIX: was missing return; function returned undefined
}

function run() {
    let val = wave_hash(10n);
    let buf=Buffer.alloc(8);
    buf.writeBigUInt64BE(val,0);
    console.log(buf.toString('base64'));
}
run();
