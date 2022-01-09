/* Peter Zhou */
#include <stdio.h>


/* main function */
int main(void) {
    char a[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char b[6] = {'t', 'h', 'e', 'r', 'e', '\0'};

    printf("%s\n", a);
    printf("%s\n", b);

    for (int i = 5; i <= 16; ++i) {
        b[i] = 'j';
    }

    printf("%s\n", a);
    printf("%s\n", b);

    for (int i = 0; i <= 6; ++i) {
        printf("a[%i] = 0x%x\n", i, &(a[i]));
    }

    for (int i = 0; i <= 6; ++i) {
        printf("b[%i] = 0x%x\n", i, &(b[i]));
    }

    /* the addresses for the a array directly follows
    the addresses for the b array. Thus the overflow 
    of the b array overwrote the contents of the a array */

    return 0;
}