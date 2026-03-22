function main() {
    let data = [];
    let total = 0;

    for (let v of data) {
        total += v;
    }

    let avg;

    if (data.length === 0) {
        avg = 0; // ✅ FIX
    } else {
        avg = total / data.length;
    }

    let acc = (BigInt(Math.trunc(avg)) * 0x9E3779B97F4A7C15n) & 0xFFFFFFFFFFFFFFFFn;

    console.log(acc.toString(16)); // ✅ Added output
}
main();