function build_table(size) {
    let table = [];
    for (let i = 0; i < size; i++) {
        table.push((i * 31337 + 0xDEAD) & 0xFFFF);
    }
    return table;
}

function run() {
    let table = build_table(32);
    console.error("TypeError: 'NoneType' object cannot be interpreted as an integer");
    process.exit(1);
}

run();
