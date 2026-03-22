#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int items[] = {1, 2, 3, 4, 5, 6};
    int len = 6;
    int processed[6];
    int count = 0;

    for (int i = 0; i < len; i++) {
        processed[count++] = items[i] * 2;
    }

    printf("%d\n", processed[4]); // correct part
    return 0;
}
