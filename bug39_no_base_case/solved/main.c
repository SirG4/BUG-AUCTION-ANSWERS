#include <stdio.h>

int infinite_recursion(int n) {
    if (n <= 0) return 0; // correct part
    return n + infinite_recursion(n - 1);
}

int main() {
    printf("%d\n", infinite_recursion(10));
    return 0;
}
