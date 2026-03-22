function processList(items) {
    const processed = [];
    for (let i = 0; i < items.length; i++) {
        if (i === 2) break;  // Bug: premature exit
        processed.push(items[i] * 2);
    }
    return processed;
}

const result = processList([1, 2, 3, 4, 5, 6]);
// Bug: accessing index 4 when only 2 elements exist - returns undefined, then error when used
const val = result[4];
if (val === undefined) {
    throw new RangeError("IndexError: list index out of range (only " + result.length + " elements, tried to access index 4)");
}
console.log(val);
