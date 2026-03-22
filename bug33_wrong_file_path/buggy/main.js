const fs = require('fs');

function run() {
    let path = "/nonexistent/path/data.bin";
    try {
        let data = fs.readFileSync(path);
    } catch (e) {
        throw new Error("FileNotFoundError: [Errno 2] No such file or directory: '" + path + "'");
    }
}
run();
