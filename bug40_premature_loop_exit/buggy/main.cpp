#include <iostream>
#include <vector>
#include <stdexcept>

/* Bug: loop breaks at i==2, so processed only has 2 elements.
   Accessing index 4 causes out_of_range exception (IndexError equivalent). */
int main() {
    std::vector<int> items = {1, 2, 3, 4, 5, 6};
    std::vector<int> processed;

    for (int i = 0; i < (int)items.size(); i++) {
        if (i == 2) break;  /* Bug: premature exit */
        processed.push_back(items[i] * 2);
    }

    /* Bug: accessing index 4 when only 2 elements exist - throws std::out_of_range */
    std::cout << processed.at(4) << std::endl;
    return 0;
}
