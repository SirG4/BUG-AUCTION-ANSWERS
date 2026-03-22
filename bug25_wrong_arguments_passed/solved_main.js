function xor_chain(values, key) {
    let acc=key;
    for(let v of values){
        acc^=BigInt(v);
        acc=BigInt.asUintN(64,acc*0x9E3779B97F4A7C15n);
        acc=BigInt.asUintN(64,(acc<<13n)|(acc>>51n));
    }
    return acc;
}

function run() {
    let data=[0xAAn,0xBBn,0xCCn,0xDDn,0xEEn,0xFFn,0x11n,0x22n,0x33n,0x44n];
    let key=0xFEEDFACECAFEBEEFn;
    // FIX: was xor_chain(key, data) — arguments were swapped
    let result = xor_chain(data, key);
    let buf=Buffer.alloc(8);
    buf.writeBigUInt64BE(result,0);
    console.log(buf.toString('base64'));
}
run();
