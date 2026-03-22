function spiral_sum(n)
    let total = 0n;
    let x = 0n, y = 0n;
    let dx = 1n, dy = 0n;
    let steps = 1n, count = 0n, turns = 0n;
    for (let i = 1n; i <= BigInt(n); i++) {
        let term = i * ((x * 0x9E3779B9n) ^ (y * 0x6C62272En));
        total = (total + term) & 0xFFFFFFFFFFFFFFFFn;
        x += dx;
        y += dy;
        count += 1n;
        if (count === steps) {
            let temp_dx = dx;
            dx = -dy;
            dy = temp_dx;
            turns += 1n;
            count = 0n;
            if (turns % 2n === 0n) {
                steps += 1n;
            }
        }
    }
    return total;
}

let result = spiral_sum(100);

let buffer = Buffer.alloc(8);
buffer.writeBigUInt64BE(result);
console.log(buffer.toString('base64'));
