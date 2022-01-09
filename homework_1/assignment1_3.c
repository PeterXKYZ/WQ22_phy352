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
    
    return 0;
}