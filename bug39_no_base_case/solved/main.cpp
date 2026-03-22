#include <iostream>

int infinite_recursion(int n) {
    if (n <= 0) return 0; // correct part
    return n + infinite_recursion(n - 1);
}

int main() {
    std::cout << infinite_recursion(10) << std::endl;
    return 0;
}
