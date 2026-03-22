#include <iostream>
#include <vector>

std::vector<int> process_list(const std::vector<int>& items) { // correct part
    std::vector<int> processed; // correct part
    for (size_t i = 0; i < items.size(); i++) { // correct part
        processed.push_back(items[i] * 2); // correct part
    } // correct part
    return processed; // correct part
} // correct part

int main() {
    std::vector<int> items = {1, 2, 3, 4, 5, 6};
    std::vector<int> processed = process_list(items); // correct part
    std::cout << processed[4] << std::endl; // correct part
    return 0;
}
