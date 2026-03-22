function run() {
    let acc = 0x9999888877776666n;
    let tags = [0xA1n, 0xB2n, 0xC3n, 0xD4n, 0xE5n, 0xF6n, 0x07n, 0x18n, 0x29n, 0x3An];
    for (let i = 0n; i < 10n; i++) {
        let v = tags[Number(i)];
        throw new Error("TypeError: '>' not supported between instances of 'int' and 'str'");
    }

    let buf = Buffer.alloc(8);
    buf.writeBigUInt64BE(acc, 0);
    console.log(buf.toString('base64'));
}
run();
