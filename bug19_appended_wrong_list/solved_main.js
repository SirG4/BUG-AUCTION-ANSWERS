function run() {
    let evens=[], odds=[];
    for(let n=1n; n<=20n; n++){
        if(n%2n===0n) evens.push(n);
        else odds.push(n);  // FIX: was evens.push(n); odd numbers must go to odds
    }
    let acc=0n;
    let ml=Math.min(evens.length,odds.length);
    for(let i=0;i<ml;i++){
        let e=evens[i],o=odds[i];
        acc^=(e*o)<<BigInt(i%8);
        acc=BigInt.asUintN(64,acc*0x9E3779B97F4A7C15n);
        acc=BigInt.asUintN(64,(acc<<11n)|(acc>>53n));
    }
    let buf=Buffer.alloc(8); buf.writeBigUInt64BE(acc,0);
    console.log(buf.toString('base64'));
}
run();
