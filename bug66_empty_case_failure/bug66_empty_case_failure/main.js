function main() {
    let data = [];
    let total = 0;
    for (let v of data) {
        total += v;
    }
    if (data.length === 0) {
        console.error("ZeroDivisionError: division by zero");
        process.exit(1);
    }
    let avg = total / data.length;
    let acc = (BigInt(Math.trunc(avg)) * 0x9E3779B97F4A7C15n) & 0xFFFFFFFFFFFFFFFFn;
}
main();
