function run() {
    let acc=0x1234567890ABCDEFn;
    for(let i=1n;i<=10n;i++){
        acc^=acc>>33n;
        acc=BigInt.asUintN(64,acc*0xFF51AFD7ED558CCDn);  // FIX: was + ; must use *
        acc^=acc>>33n;
        acc=BigInt.asUintN(64,acc*0xC4CEB9FE1A85EC53n);  // FIX: was + ; must use *
        acc^=acc>>33n;
        acc=BigInt.asUintN(64,acc^(i*0xDEAD0000n));
    }
    let buf=Buffer.alloc(8);
    buf.writeBigUInt64BE(acc,0);
    console.log(buf.toString('base64'));
}
run();
