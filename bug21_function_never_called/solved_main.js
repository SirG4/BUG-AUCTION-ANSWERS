function diamond_hash() {
    let pts = [];
    for(let i=-5;i<=5;i++)
        for(let j=-5;j<=5;j++)
            if(Math.abs(i)+Math.abs(j)<=5) pts.push([BigInt(i),BigInt(j)]);
    let acc=0n;
    let limit=Math.min(pts.length,10);
    for(let step=0;step<limit;step++){
        let x=pts[step][0], y=pts[step][1];
        let xp=BigInt.asUintN(64,x*0xDEADn), yp=BigInt.asUintN(64,y*0xBEEFn);
        acc^=xp^yp;
        acc=BigInt.asUintN(64,acc*0x9E3779B97F4A7C15n);
        let sl=BigInt(step%11+1), sr=BigInt(63-step%11);
        acc=BigInt.asUintN(64,(acc<<sl)|(acc>>sr));
    }
    return acc;
}

function run() {
    let result = diamond_hash();   // FIX: was "placeholder = 0n"; must call diamond_hash()
    let buf=Buffer.alloc(8);
    buf.writeBigUInt64BE(result,0);
    console.log(buf.toString('base64'));
}
run();
