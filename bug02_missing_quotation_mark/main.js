function stringToBigInt(str) {
    let buf = Buffer.from(str, 'utf8');
    let val = 0n;
    for (let i = 0; i < buf.length; i++) {
        val = (val << 8n) | BigInt(buf[i]);
    }
    return val;
}

function build_hash(parts) {
    let acc = 0n;
    for (let idx = 0n; idx < parts.length; idx++) {
        let val = stringToBigInt(parts[idx]) & 0xFFFFFFFFFFFFFFFFn;
        acc = (acc ^ val) * 0x9E3779B97F4A7C15n;
        acc &= 0xFFFFFFFFFFFFFFFFn;
        
        let shift = (idx % 7n) + 1n;
        acc = ((acc << shift) | (acc >> (64n - shift))) & 0xFFFFFFFFFFFFFFFFn;
    }
    return acc;
}

let tokens = ["alpha", "bravo, "charlie", "delta", "echo",
              "foxtrot", "golf", "hotel", "india", "juliet"];
let result = build_hash(tokens);

let buffer = Buffer.alloc(8);
buffer.writeBigUInt64BE(result);
console.log(buffer.toString('base64'));
