#include <stdio.h>
#include <stdlib.h>

/* Bug: loop breaks at i==2, so processed only has 2 elements.
   Accessing processed[4] causes out-of-bounds (IndexError equivalent). */
int main(void) {
    int items[] = {1, 2, 3, 4, 5, 6};
    int len = 6;
    int processed[6];
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (i == 2) break;  /* Bug: premature exit */
        processed[count++] = items[i] * 2;
    }

    /* Bug: accessing index 4 when only 2 elements exist */
    printf("%d\n", processed[4]);  /* undefined behavior / out-of-bounds */
    return 0;
}
