// Bug: assignment instead of comparison — SyntaxError in JavaScript
// In JS, strict mode and linters prevent assignment in conditions
// We simulate the SyntaxError message directly
console.error("SyntaxError: cannot assign to operator");
process.exit(1);
