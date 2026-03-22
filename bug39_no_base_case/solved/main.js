function infinite_recursion(n) {
    if (n <= 0) return 0; // correct part
    return n + infinite_recursion(n - 1);
}
console.log(infinite_recursion(10));
