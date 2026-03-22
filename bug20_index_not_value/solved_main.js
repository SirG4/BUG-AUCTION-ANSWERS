function run() {
    let items = [0x100n,0x200n,0x300n,0x400n,0x500n,0x600n,0x700n,0x800n,0x900n,0xA00n];
    let acc = 0xBEEFBEEFBEEFBEEFn;
    for (let i = 0n; i < 10n; i++) {
        let v = items[Number(i)];
        acc ^= v;                              // FIX: was acc ^= i; use value v not index i
        acc = BigInt.asUintN(64, acc * 0x9E3779B97F4A7C15n);
        let sl = v % 15n + 1n, sr = 63n - (v % 15n);  // FIX: shift by v not i
        acc = BigInt.asUintN(64, (acc << sl) | (acc >> sr));
        acc ^= v >> 2n;                        // FIX: was i >> 2n; use value v
    }
    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}
run();
