/* Peter Zhou */
#include <stdio.h>

#define HEIGHT 5
#define BASE 9

/* main function */

int main(void) {

    // first triangle
    for (int i = 1; i <= HEIGHT; ++i) {
        for (int k = 0; k <= BASE-i; ++k) {
            putchar(' ');
        }
        for (int j = 1; j <= 2*i-1; ++j) {
            putchar('*');
        }
        putchar('\n');
    }

    // other two triangles
    for (int i = 1; i <= HEIGHT; ++i) {
        for (int k = 1; k <= HEIGHT-i; ++k) {
            putchar(' ');
        }
        for (int j = 1; j <= 2*i-1; ++j) {
            putchar('*');
        }
        for (int k = 1; k <= BASE-2*(i-1); ++k) {
            putchar(' ');
        }
        for (int l = 1; l <= 2*i-1; ++l) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}