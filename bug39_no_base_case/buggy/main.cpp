#include <iostream>

int infinite_recursion(int n) {
    return n + infinite_recursion(n - 1);
}

int main() {
    std::cout << infinite_recursion(10) << std::endl;
    return 0;
}
