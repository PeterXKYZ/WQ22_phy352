/* Peter Zhou */
#include <stdio.h>
#define ARRAY_SIZE 100

int main(void) {
    printf("Please input some characters ...\n\n");

    char carray[ARRAY_SIZE];

    while (fgets(carray, ARRAY_SIZE, stdin) != NULL) {
        printf("Your input: %s\n", carray);
    }
}

