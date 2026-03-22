function run() {
    let data = [];
    for (let i = 0n; i < 10n; i++) {
        data.push(0x1A2Bn << i);
    }
    throw new Error("TypeError: unsupported operand type(s) for ^=: 'NoneType' and 'int'");
}
run();
