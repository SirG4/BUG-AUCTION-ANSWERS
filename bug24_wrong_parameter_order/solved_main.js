function weighted_mix(base, weight, offset) {
    let acc=base;
    for(let i=0n;i<10n;i++){
        acc^=(weight*i+offset);
        acc=BigInt.asUintN(64,acc*0x9E3779B97F4A7C15n);
        acc=BigInt.asUintN(64,(acc<<(i%7n+1n))|(acc>>(63n-i%7n)));
    }
    return acc;
}

function run() {
    let base_val=0xCAFEBABE12345678n, weight_val=0x100n, offset_val=0xDEADn;
    // FIX: was weighted_mix(weight_val, base_val, offset_val) — args were swapped
    let result = weighted_mix(base_val, weight_val, offset_val);
    let buf=Buffer.alloc(8);
    buf.writeBigUInt64BE(result,0);
    console.log(buf.toString('base64'));
}
run();
