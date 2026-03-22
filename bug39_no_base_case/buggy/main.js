function infinite_recursion(n) {
    return n + infinite_recursion(n - 1);
}

console.log(infinite_recursion(10));
